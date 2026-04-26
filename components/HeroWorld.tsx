import Image from "next/image";
import Link from "next/link";
import type { CSSProperties } from "react";
import { CalendarIcon } from "@/components/Icons";
import { formatDate, todayKey } from "@/lib/date";
import type { Solution } from "@/lib/types";

export function HeroWorld({ featured, recent }: { featured?: Solution; recent: Solution[] }) {
  const orbitItems = recent.slice(0, 5);

  return (
    <div className="hero-world pointer-events-none absolute inset-0 overflow-hidden bg-[#03140a] text-white">
      <div className="absolute inset-0 bg-[radial-gradient(circle_at_50%_18%,rgba(52,211,153,0.30),transparent_18rem),linear-gradient(140deg,rgba(6,78,59,0.74),rgba(2,6,23,0.94)_56%,rgba(0,0,0,0.96))]" />
      <div className="absolute inset-0 bg-[linear-gradient(90deg,rgba(0,0,0,0.48)_0%,rgba(0,0,0,0.10)_50%,rgba(0,0,0,0.48)_100%)]" />
      <div className="absolute inset-x-2 bottom-0 h-[86%] rounded-t-full border border-emerald-300/20 bg-[radial-gradient(circle_at_50%_50%,rgba(16,185,129,0.28),transparent_22rem),linear-gradient(180deg,rgba(12,74,55,0.52),rgba(0,0,0,0.20))] shadow-[inset_0_0_120px_rgba(52,211,153,0.16)] sm:inset-x-8" />
      <div className="hero-world-grid absolute inset-x-2 bottom-0 h-[86%] rounded-t-full opacity-75 sm:inset-x-8" />
      <div className="hero-orbit-guide hero-orbit-glow absolute z-0 rounded-full" />

      <div className="hero-brand-badge absolute left-1/2 z-20 flex -translate-x-1/2 items-center gap-3 rounded-full border border-emerald-300/25 bg-[#03140a]/72 px-4 py-3 shadow-[0_24px_70px_-42px_rgba(16,185,129,0.95)] backdrop-blur-2xl sm:gap-4 sm:px-8 sm:py-4">
        <span className="grid h-10 w-10 shrink-0 place-items-center overflow-hidden rounded-full border border-emerald-300/30 bg-black shadow-glow sm:h-12 sm:w-12">
          <Image src="/GEEKDEVSS_Logo.png" alt="GEEKDEVSS logo" width={48} height={48} className="h-full w-full object-cover" />
        </span>
        <div className="min-w-0">
          <p className="whitespace-nowrap text-xl font-black italic tracking-tight text-white sm:text-5xl">GEEKDEVSS</p>
          <p className="hidden text-xs font-semibold uppercase tracking-[0.24em] text-emerald-200/62 sm:block">Daily coding archive</p>
        </div>
      </div>

      <div className="hero-feature-card pointer-events-auto absolute left-1/2 z-20 w-[min(34rem,calc(100%-2rem))] -translate-x-1/2 -translate-y-1/2">
        {featured ? (
          <Link href={`/solutions/${featured.slug}`} className="block rounded-[1.6rem] border border-emerald-300/35 bg-[#07110c]/74 p-5 shadow-[0_28px_90px_-38px_rgba(16,185,129,0.95)] backdrop-blur-2xl transition hover:-translate-y-1 hover:bg-[#092018]/82 sm:p-6">
            <div className="flex items-center justify-between gap-3">
              <span className="inline-flex items-center gap-2 rounded-full bg-emerald-400 px-3 py-1 text-xs font-black text-[#03140a]">
                <CalendarIcon className="h-3.5 w-3.5" />
                {featured.date === todayKey() ? "Today" : "Latest"}
              </span>
              <span className="text-xs font-semibold text-emerald-100/72">{formatDate(featured.date)}</span>
            </div>
            <h2 className="mt-5 line-clamp-2 text-2xl font-black tracking-tight sm:text-3xl">{featured.title}</h2>
            <p className="mt-3 line-clamp-2 text-sm leading-6 text-white/72 sm:text-base">{featured.summary}</p>
          </Link>
        ) : (
          <div className="rounded-3xl border border-emerald-300/30 bg-white/12 p-5 text-center backdrop-blur-2xl">
            <h2 className="text-xl font-black">No solutions indexed yet</h2>
            <p className="mt-2 text-sm text-white/64">Run `npm run generate:solutions` after adding files.</p>
          </div>
        )}
      </div>

      <div className="hero-orbit absolute inset-0 z-10">
        {orbitItems.map((solution, index) => (
          <Link
            key={solution.slug}
            href={`/solutions/${solution.slug}`}
            className="hero-orbit-card pointer-events-auto rounded-2xl border border-white/12 bg-[#07110c]/84 p-3 text-white shadow-[0_18px_48px_-28px_rgba(52,211,153,0.9)] backdrop-blur-xl"
            style={{ "--orbit-delay": `${index * -3.6}s` } as CSSProperties}
          >
            <div className="flex items-center gap-2">
              <span className="grid h-8 w-8 shrink-0 place-items-center overflow-hidden rounded-full border border-emerald-300/20 bg-black">
                <Image src="/GEEKDEVSS_Logo.png" alt="" width={32} height={32} className="h-full w-full object-cover" />
              </span>
              <div className="min-w-0">
                <p className="truncate text-sm font-black">{solution.title}</p>
                <p className="mt-0.5 text-xs font-semibold text-emerald-100/58">{solution.language} - {formatDate(solution.date)}</p>
              </div>
            </div>
          </Link>
        ))}
      </div>
    </div>
  );
}
