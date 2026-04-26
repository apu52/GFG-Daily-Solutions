import fs from "node:fs";
import path from "node:path";
import { execFileSync } from "node:child_process";

const root = process.cwd();
const outputPath = path.join(root, "data", "solutions.json");
const sourceExtensions = new Set([".cpp", ".cc", ".cxx", ".c", ".java", ".py", ".js", ".ts", ".go", ".rs", ".md", ".mdx"]);
const ignoredDirs = new Set([".git", ".next", "node_modules", "app", "components", "lib", "data", "scripts", "public", ".github"]);
const ignoredFiles = new Set([
  "CONTRIBUTING.md",
  "README.md",
  "next-env.d.ts",
  "next.config.mjs",
  "postcss.config.mjs",
  "tailwind.config.ts"
]);

const repoUrl = process.env.NEXT_PUBLIC_GITHUB_REPO_URL || getRemoteUrl() || "https://github.com/apu52/GFG-Daily-Solutions";
const branch = process.env.NEXT_PUBLIC_GITHUB_BRANCH || getDefaultBranch();
const seenSlugs = new Map();
const previousSolutions = readPreviousSolutions();

fs.mkdirSync(path.dirname(outputPath), { recursive: true });

const files = walk(root)
  .filter((filePath) => sourceExtensions.has(path.extname(filePath).toLowerCase()))
  .filter((filePath) => !ignoredFiles.has(path.relative(root, filePath)))
  .sort((a, b) => a.localeCompare(b));

const solutions = files.map((absolutePath) => buildSolution(absolutePath));
fs.writeFileSync(outputPath, `${JSON.stringify(solutions, null, 2)}\n`);
console.log(`Generated ${solutions.length} solutions at ${path.relative(root, outputPath)}`);

function walk(directory) {
  return fs.readdirSync(directory, { withFileTypes: true }).flatMap((entry) => {
    const absolutePath = path.join(directory, entry.name);
    if (entry.isDirectory()) {
      return ignoredDirs.has(entry.name) ? [] : walk(absolutePath);
    }
    return entry.isFile() ? [absolutePath] : [];
  });
}

function buildSolution(absolutePath) {
  const filePath = slash(path.relative(root, absolutePath));
  const ext = path.extname(absolutePath).toLowerCase();
  const rawCode = fs.readFileSync(absolutePath, "utf8");
  const { frontmatter, code } = parseFrontmatter(rawCode);
  const parsed = parseFileName(path.basename(absolutePath, ext));
  const previous = previousSolutions.get(filePath);
  const title = frontmatter.title || parsed.title;
  const date = frontmatter.date || parsed.date || getFirstAddedDate(filePath) || getLastCommitDate(filePath) || previous?.date || toDateKey(fs.statSync(absolutePath).mtime);
  const language = frontmatter.language || parsed.language || languageFromExtension(ext);
  const platform = frontmatter.platform || inferPlatform(title, filePath);
  const difficulty = normalizeDifficulty(frontmatter.difficulty);
  const problemNumber = frontmatter.problemNumber || parsed.problemNumber;
  const slug = uniqueSlug(`${date}-${problemNumber ? `${problemNumber}-` : ""}${title}-${language}`);

  return {
    slug,
    title,
    date,
    platform,
    ...(difficulty ? { difficulty } : {}),
    language,
    extension: ext.replace(".", ""),
    filePath,
    githubUrl: `${repoUrl.replace(/\/$/, "")}/blob/${branch}/${encodeURIComponentPath(filePath)}`,
    ...(problemNumber ? { problemNumber } : {}),
    summary: frontmatter.summary || buildSummary(title, platform, language),
    code: code.trimEnd()
  };
}

function uniqueSlug(value) {
  const base = slugify(value);
  const count = seenSlugs.get(base) ?? 0;
  seenSlugs.set(base, count + 1);
  return count === 0 ? base : `${base}-${count + 1}`;
}

function parseFileName(baseName) {
  const dateMatch = baseName.match(/^(\d{4}-\d{2}-\d{2})[-_\s]+(.+)$/);
  const datedName = dateMatch ? dateMatch[2] : baseName;
  const numberMatch = datedName.match(/^(\d+)\.\s*(.+)$/);
  const nameWithoutNumber = numberMatch ? numberMatch[2] : datedName;
  const cleaned = nameWithoutNumber.replace(/[_-]+/g, " ").replace(/\s+/g, " ").trim();
  const languageToken = cleaned.match(/\b(cpp|c\+\+|java|python|py|javascript|typescript|go|rust)\b$/i);
  const title = titleCase(languageToken ? cleaned.slice(0, languageToken.index).trim() : cleaned);

  return {
    date: dateMatch?.[1],
    problemNumber: numberMatch?.[1],
    title,
    language: languageToken ? normalizeLanguage(languageToken[1]) : undefined
  };
}

function parseFrontmatter(rawCode) {
  if (!rawCode.startsWith("---")) {
    return { frontmatter: {}, code: rawCode };
  }

  const closing = rawCode.indexOf("\n---", 3);
  if (closing === -1) {
    return { frontmatter: {}, code: rawCode };
  }

  const block = rawCode.slice(3, closing).trim();
  const frontmatter = Object.fromEntries(
    block.split(/\r?\n/).map((line) => {
      const [key, ...value] = line.split(":");
      return [key.trim(), value.join(":").trim().replace(/^["']|["']$/g, "")];
    }).filter(([key, value]) => key && value)
  );

  return { frontmatter, code: rawCode.slice(closing + 4).trimStart() };
}

function inferPlatform(title, filePath) {
  const value = `${title} ${filePath}`.toLowerCase();
  if (value.includes("leetcode")) return "LeetCode";
  return "GEEKDEVSS";
}

function languageFromExtension(ext) {
  const languages = {
    ".cpp": "C++",
    ".cc": "C++",
    ".cxx": "C++",
    ".c": "C",
    ".java": "Java",
    ".py": "Python",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
    ".md": "Markdown",
    ".mdx": "MDX"
  };
  return languages[ext] ?? ext.replace(".", "").toUpperCase();
}

function normalizeLanguage(value) {
  const normalized = value.toLowerCase();
  if (["cpp", "c++"].includes(normalized)) return "C++";
  if (["py", "python"].includes(normalized)) return "Python";
  if (normalized === "javascript") return "JavaScript";
  if (normalized === "typescript") return "TypeScript";
  return titleCase(value);
}

function normalizeDifficulty(value) {
  if (!value) return undefined;
  const normalized = value.toLowerCase();
  if (normalized === "easy") return "Easy";
  if (normalized === "medium") return "Medium";
  if (normalized === "hard") return "Hard";
  return undefined;
}

function buildSummary(title, platform, language) {
  return `${language} solution for ${title} from ${platform}.`;
}

function titleCase(value) {
  return value.replace(/\w\S*/g, (word) => {
    if (/^[A-Z0-9]+$/.test(word)) return word;
    return word.charAt(0).toUpperCase() + word.slice(1);
  });
}

function slugify(value) {
  return value
    .toLowerCase()
    .replace(/&/g, " and ")
    .replace(/[^a-z0-9]+/g, "-")
    .replace(/^-+|-+$/g, "");
}

function slash(value) {
  return value.split(path.sep).join("/");
}

function encodeURIComponentPath(filePath) {
  return filePath.split("/").map(encodeURIComponent).join("/");
}

function toDateKey(date) {
  return date.toISOString().slice(0, 10);
}

function readPreviousSolutions() {
  try {
    const solutions = JSON.parse(fs.readFileSync(outputPath, "utf8"));
    return new Map(solutions.map((solution) => [solution.filePath, solution]));
  } catch {
    return new Map();
  }
}

function git(args) {
  return execFileSync("git", args, { encoding: "utf8" }).trim() || undefined;
}

function getFirstAddedDate(filePath) {
  try {
    return git(["log", "--all", "--diff-filter=A", "--follow", "--format=%ad", "--date=short", "--", filePath])
      ?.split(/\r?\n/)
      .filter(Boolean)
      .at(-1);
  } catch {
    return undefined;
  }
}

function getLastCommitDate(filePath) {
  try {
    return git(["log", "--all", "-1", "--format=%ad", "--date=short", "--", filePath]);
  } catch {
    return undefined;
  }
}

function getRemoteUrl() {
  try {
    const remote = git(["remote", "get-url", "origin"]);
    return remote.replace(/^git@github.com:/, "https://github.com/").replace(/\.git$/, "");
  } catch {
    return undefined;
  }
}

function getDefaultBranch() {
  try {
    return git(["rev-parse", "--abbrev-ref", "HEAD"]) || "main";
  } catch {
    return "main";
  }
}
