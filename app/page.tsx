import Link from "next/link";
import { HeroWorld } from "@/components/HeroWorld";
import { SolutionCard } from "@/components/SolutionCard";
import { getFeaturedSolution } from "@/lib/date";
import { getRecentSolutions, getSolutions } from "@/lib/solutions";

export default function HomePage() {
  const solutions = getSolutions();
  const featured = getFeaturedSolution(solutions);
  const recent = getRecentSolutions(6);

  return (
    <div className="mx-auto max-w-7xl px-4 pb-10 pt-2 sm:px-6 lg:px-8">
      <section className="relative min-h-[40rem] overflow-hidden rounded-[1.75rem] border border-emerald-900/10 bg-[#03140a] shadow-glow dark:border-white/10 sm:min-h-[44rem] lg:min-h-[calc(100vh-6rem)]">
        <HeroWorld featured={featured ?? undefined} recent={recent} />
      </section>

      <section className="mt-12">
        <div className="mb-5 flex items-end justify-between gap-4">
          <div>
            <p className="text-sm font-semibold uppercase tracking-[0.22em] text-emerald-700 dark:text-emerald-300">Recent</p>
            <h2 className="mt-2 text-3xl font-semibold tracking-tight text-ink dark:text-white">Latest solutions</h2>
          </div>
          <Link href="/solutions" className="hidden rounded-full border border-emerald-900/10 px-4 py-2 text-sm font-semibold text-emerald-700 transition hover:bg-emerald-50 dark:border-white/10 dark:text-emerald-200 dark:hover:bg-white/5 sm:inline-flex">
            View all
          </Link>
        </div>
        <div className="grid gap-4 md:grid-cols-2 xl:grid-cols-3">
          {recent.map((solution) => <SolutionCard key={solution.slug} solution={solution} />)}
        </div>
      </section>
    </div>
  );
}
