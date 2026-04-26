# Contributing

Thanks for helping improve the GEEKDEVSS solution library. This repo contains solution files and a Next.js website that generates the public archive from those files.

## Add a Solution

Add your solution file in the repository root using a clear problem name and the correct language extension.

Examples:

```txt
Two Sum.cpp
Add 1 to a Linked List Number.cpp
Account Merge.py
```

Supported examples include `.cpp`, `.java`, `.py`, `.js`, `.ts`, `.go`, and `.rs`.

The website generator reads solution files and creates `data/solutions.json`. That generated data powers the home orbit, today's problem, recent section, calendar, search page, and solution detail pages.

## Optional Metadata

If the generated title/date/platform needs to be customized, add frontmatter at the top of the solution file:

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

Then place the solution code below the frontmatter.

## Force a Date

Normally, the calendar date is detected from Git history. To force a date manually, use this filename format:

```txt
YYYY-MM-DD-problem-name-language.ext
```

Example:

```txt
2026-04-26-common-in-3-sorted-arrays-cpp.cpp
```

## Run Locally

Install dependencies:

```bash
npm install
```

Regenerate the solution manifest:

```bash
npm run generate:solutions
```

Start the app:

```bash
npm run dev
```

Open:

```txt
http://localhost:3000
```

## Before Opening a Pull Request

Run these checks:

```bash
npm run lint
npm run build
```

Make sure:

- The solution file has a clear name.
- The code is complete and readable.
- The generated website pages still build successfully.
- You do not remove or rename unrelated solution files.
- You do not commit unrelated formatting or generated noise.

## Pull Request Notes

In your PR description, mention:

- The problem name.
- The language used.
- The platform, if relevant.
- Any special notes about the approach.

After a PR is merged into `main`, Vercel rebuilds the website and updates the archive automatically.
