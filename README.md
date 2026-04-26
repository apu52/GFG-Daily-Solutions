# GEEKDEVSS Solution Library

A production-ready Next.js app that turns this GitHub repository of GEEKDEVSS and LeetCode solutions into a fast public solution library.

## Features

- Dashboard with today's solution, falling back to the latest available entry
- Searchable archive with platform, language, and difficulty filters
- Date explorer for browsing solutions by day
- Detail pages with syntax-highlighted code preview, copy-to-clipboard, and GitHub source link
- Light and dark themes with green-accented polished UI
- Repository-driven `data/solutions.json` manifest generated from solution files
- Vercel-compatible Next.js App Router setup

## Project Structure

```txt
app/
  calendar/page.tsx
  solutions/page.tsx
  solutions/[slug]/page.tsx
  globals.css
  layout.tsx
  page.tsx
components/
  Badge.tsx
  CalendarExplorer.tsx
  CodeBlock.tsx
  CopyButton.tsx
  SearchLibrary.tsx
  SolutionCard.tsx
  ThemeToggle.tsx
data/
  solutions.json
lib/
  date.ts
  search.ts
  slugs.ts
  solutions.ts
  types.ts
scripts/
  generate-solutions.mjs
.github/workflows/
  update-solutions.yml
```

## Data Schema

Each generated solution entry uses this shape:

```ts
type Solution = {
  slug: string;
  title: string;
  date: string;
  platform: "GEEKDEVSS" | "LeetCode" | "Other";
  difficulty?: "Easy" | "Medium" | "Hard";
  language: string;
  extension: string;
  filePath: string;
  githubUrl: string;
  problemNumber?: string;
  summary: string;
  code: string;
};
```

## Add a New Solution

You can add files normally with just the problem name and language extension:

```txt
Problem Name.ext
```

Example:

```txt
Two Sum.cpp
Add 1 to a Linked List Number.cpp
Account Merge.py
```

The calendar date is read from Git automatically using the date the file was first added. If you want to force a date manually, this filename format is also supported:

```txt
YYYY-MM-DD-problem-name-language.ext
```

Optional frontmatter at the top of a file can override generated metadata when needed:

```txt
---
title: Two Sum
date: 2026-04-26
platform: LeetCode
difficulty: Easy
language: C++
problemNumber: 1
summary: Hash map based linear-time solution.
---
```

Then regenerate the manifest locally:

```bash
npm run generate:solutions
```

## Local Development

```bash
npm install
npm run generate:solutions
npm run dev
```

Open `http://localhost:3000`.

## Deploy to Vercel

1. Push this repository to GitHub.
2. Import the repository in Vercel.
3. Keep the default build command:

```bash
npm run build
```

4. Optionally set these environment variables:

```txt
NEXT_PUBLIC_GITHUB_REPO_URL=https://github.com/apu52/GFG-Daily-Solutions
NEXT_PUBLIC_GITHUB_BRANCH=main
```

The build command runs `scripts/generate-solutions.mjs` before `next build`, so Vercel always builds with the latest repository contents.

## Automatic Manifest Updates

`.github/workflows/update-solutions.yml` regenerates `data/solutions.json` when solution files are pushed to `main`. Vercel can also rebuild directly from every push, so the site updates without manual UI edits.
