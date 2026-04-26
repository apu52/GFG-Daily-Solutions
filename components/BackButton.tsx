"use client";

import Link from "next/link";
import { useRouter } from "next/navigation";
import { ArrowLeftIcon } from "@/components/Icons";

export function BackButton({ fallback = "/", fallbackLabel = "Home", label = "Back" }: { fallback?: string; fallbackLabel?: string; label?: string }) {
  const router = useRouter();

  return (
    <div className="mb-7 flex items-center gap-3">
      <button
        type="button"
        onClick={() => router.back()}
        className="inline-flex h-10 items-center gap-2 rounded-full border border-emerald-900/10 bg-white/75 px-4 text-sm font-semibold text-ink shadow-sm transition hover:-translate-x-0.5 hover:border-emerald-500/40 hover:bg-emerald-50 dark:border-white/10 dark:bg-white/5 dark:text-white dark:hover:bg-emerald-400/10"
      >
        <ArrowLeftIcon className="h-4 w-4" />
        {label}
      </button>
      <Link href={fallback} className="text-sm font-semibold text-emerald-700 transition hover:text-emerald-600 dark:text-emerald-200 dark:hover:text-emerald-100">
        {fallbackLabel}
      </Link>
    </div>
  );
}
