import Image from "next/image";
import { BackButton } from "@/components/BackButton";

export const metadata = {
  title: "LeetCode Preview | GEEKDEVSS"
};

export default function LeetCodePreviewPage() {
  return (
    <div className="mx-auto max-w-7xl px-4 py-10 sm:px-6 lg:px-8">
      <BackButton />
      <div className="mb-8">
        <p className="text-sm font-semibold uppercase tracking-[0.22em] text-emerald-700 dark:text-emerald-300">Embedded archive</p>
        <h1 className="mt-3 text-4xl font-semibold tracking-tight text-ink dark:text-white">LeetCode solutions preview</h1>
        <p className="mt-3 max-w-2xl text-sm leading-6 text-ink/62 dark:text-white/62">
          A live iframe preview of the existing LeetCode solutions page.
        </p>
      </div>
      <section className="glass-panel overflow-hidden rounded-3xl p-2">
        <div className="flex flex-wrap items-center justify-between gap-3 border-b border-emerald-900/10 px-4 py-3 dark:border-white/10">
          <div className="flex min-w-0 items-center gap-3">
            <span className="grid h-10 w-10 shrink-0 place-items-center overflow-hidden rounded-full border border-emerald-400/25 bg-black shadow-glow">
              <Image src="/GEEKDEVSS_Logo.png" alt="GEEKDEVSS logo" width={40} height={40} className="h-full w-full object-cover" />
            </span>
            <div className="min-w-0">
              <p className="text-sm font-black text-ink dark:text-white">GEEKDEVSS iframe preview</p>
              <p className="truncate text-xs font-semibold text-ink/52 dark:text-white/52">apu52.github.io/Leetcode-Solutions</p>
            </div>
          </div>
          <a href="https://apu52.github.io/Leetcode-Solutions/" target="_blank" rel="noreferrer" className="rounded-full bg-emerald-600 px-4 py-2 text-sm font-semibold text-white transition hover:bg-emerald-500">
            Open
          </a>
        </div>
        <iframe
          title="LeetCode Solutions"
          src="https://apu52.github.io/Leetcode-Solutions/"
          className="h-[78vh] w-full rounded-2xl bg-white"
          loading="lazy"
        />
      </section>
    </div>
  );
}
