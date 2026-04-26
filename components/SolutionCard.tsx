import Link from "next/link";
import Image from "next/image";
import { Badge } from "@/components/Badge";
import { formatDate } from "@/lib/date";
import type { Solution } from "@/lib/types";

export function SolutionCard({ solution, featured = false }: { solution: Solution; featured?: boolean }) {
  return (
    <Link
      href={`/solutions/${solution.slug}`}
      className={`group glass-panel block rounded-3xl p-5 transition hover:-translate-y-0.5 hover:border-emerald-500/40 ${featured ? "md:p-7" : ""}`}
    >
      <div className="flex items-start justify-between gap-4">
        <div className="flex flex-wrap items-center gap-2">
          <span className="inline-flex items-center gap-2 rounded-full border border-emerald-500/20 bg-emerald-500/10 px-2.5 py-1 text-xs font-black text-emerald-800 dark:text-emerald-100">
            <Image src="/GEEKDEVSS_Logo.png" alt="" width={18} height={18} className="h-4 w-4 rounded-full object-cover" />
            {solution.platform}
          </span>
          {solution.difficulty && <Badge tone={solution.difficulty}>{solution.difficulty}</Badge>}
        </div>
        <span className="rounded-full border border-zinc-950/10 px-2.5 py-1 text-xs font-semibold text-ink/60 dark:border-white/10 dark:text-white/60">
          {solution.language}
        </span>
      </div>
      <h3 className={`mt-4 font-semibold tracking-tight text-ink transition group-hover:text-emerald-700 dark:text-white dark:group-hover:text-emerald-200 ${featured ? "text-3xl" : "text-xl"}`}>
        {solution.problemNumber ? `${solution.problemNumber}. ` : ""}
        {solution.title}
      </h3>
      <p className="mt-3 line-clamp-2 text-sm leading-6 text-ink/62 dark:text-white/62">{solution.summary}</p>
      <div className="mt-5 flex items-center justify-between text-sm">
        <span className="font-medium text-emerald-700 dark:text-emerald-200">{formatDate(solution.date)}</span>
        <span className="inline-flex items-center gap-2 font-semibold text-ink/55 transition group-hover:text-emerald-700 dark:text-white/55 dark:group-hover:text-emerald-200">
          View code <span aria-hidden="true">-&gt;</span>
        </span>
      </div>
    </Link>
  );
}
