import { CopyButton } from "@/components/CopyButton";
import { codeToHtml } from "shiki";

export async function CodeBlock({ code, language, fileName }: { code: string; language: string; fileName: string }) {
  const highlighted = await codeToHtml(code, {
    lang: shikiLanguage(language),
    themes: {
      light: "github-light",
      dark: "github-dark"
    },
    defaultColor: false
  });

  return (
    <section className="overflow-hidden rounded-2xl border border-zinc-950/10 bg-white shadow-glow dark:border-white/10 dark:bg-[#0d1117]">
      <div className="flex flex-wrap items-center justify-between gap-3 border-b border-zinc-950/10 bg-[#f6f8fa] px-4 py-3 dark:border-white/10 dark:bg-[#161b22]">
        <div className="flex min-w-0 items-center gap-3">
          <span className="flex gap-1.5" aria-hidden="true">
            <span className="h-3 w-3 rounded-full bg-red-400" />
            <span className="h-3 w-3 rounded-full bg-amber-300" />
            <span className="h-3 w-3 rounded-full bg-emerald-400" />
          </span>
          <span className="truncate text-sm font-semibold text-[#24292f] dark:text-[#c9d1d9]">{fileName}</span>
          <span className="hidden rounded-full border border-zinc-950/10 bg-white px-3 py-1 text-xs font-semibold text-[#57606a] dark:border-white/10 dark:bg-white/5 dark:text-[#8b949e] sm:inline-flex">{language}</span>
        </div>
        <CopyButton code={code} />
      </div>
      <div
        className="code-scroll github-code max-h-[72vh] overflow-auto bg-white text-sm leading-7 dark:bg-[#0d1117] [&_code]:font-mono [&_pre]:!m-0 [&_pre]:min-w-max [&_pre]:!bg-transparent [&_pre]:p-5"
        dangerouslySetInnerHTML={{ __html: highlighted }}
      />
    </section>
  );
}

function shikiLanguage(language: string) {
  const key = language.toLowerCase();
  const map: Record<string, string> = {
    "c++": "cpp",
    c: "c",
    java: "java",
    python: "python",
    javascript: "javascript",
    typescript: "typescript",
    go: "go",
    rust: "rust",
    markdown: "markdown",
    mdx: "mdx"
  };

  return map[key] ?? "text";
}
