import { BackButton } from "@/components/BackButton";
import { SearchLibrary } from "@/components/SearchLibrary";
import { getSolutions } from "@/lib/solutions";

export const metadata = {
  title: "Solutions Library | GEEKDEVSS"
};

export default function SolutionsPage() {
  const solutions = getSolutions();

  return (
    <div className="mx-auto max-w-7xl px-4 py-10 sm:px-6 lg:px-8">
      <BackButton />
      <div className="mb-8">
        <p className="text-sm font-semibold uppercase tracking-[0.22em] text-emerald-700 dark:text-emerald-300">GEEKDEVSS Archive</p>
        <h1 className="mt-3 text-4xl font-semibold tracking-tight text-ink dark:text-white">Searchable solution library</h1>
        <p className="mt-3 max-w-2xl text-sm leading-6 text-ink/62 dark:text-white/62">
          Filter by platform, language, difficulty, date, or problem number. Results are generated from the repository manifest.
        </p>
      </div>
      <SearchLibrary solutions={solutions} />
    </div>
  );
}
