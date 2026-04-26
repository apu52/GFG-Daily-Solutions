"use client";

import { useState } from "react";

export function CopyButton({ code }: { code: string }) {
  const [copied, setCopied] = useState(false);

  async function copyCode() {
    await navigator.clipboard.writeText(code);
    setCopied(true);
    window.setTimeout(() => setCopied(false), 1600);
  }

  return (
    <button
      type="button"
      onClick={copyCode}
      className="inline-flex items-center gap-2 rounded-full border border-emerald-300/30 bg-emerald-500 px-4 py-2 text-sm font-semibold text-white shadow-glow transition hover:bg-emerald-400"
    >
      <span className="relative h-4 w-4" aria-hidden="true">
        <span className="absolute left-1 top-0 h-3 w-3 rounded-[3px] border border-current opacity-70" />
        <span className="absolute bottom-0 left-0 h-3 w-3 rounded-[3px] border border-current bg-emerald-500" />
      </span>
      {copied ? "Copied" : "Copy"}
    </button>
  );
}
