"use client";

import { useMemo, useState } from "react";
import { SolutionCard } from "@/components/SolutionCard";
import { filterSolutions, uniqueSorted } from "@/lib/search";
import type { Solution } from "@/lib/types";

export function SearchLibrary({ solutions }: { solutions: Solution[] }) {
  const [query, setQuery] = useState("");
  const [platform, setPlatform] = useState("");
  const [language, setLanguage] = useState("");
  const [difficulty, setDifficulty] = useState("");

  const platforms = useMemo(() => uniqueSorted(solutions.map((item) => item.platform)), [solutions]);
  const languages = useMemo(() => uniqueSorted(solutions.map((item) => item.language)), [solutions]);
  const difficulties = useMemo(() => uniqueSorted(solutions.flatMap((item) => item.difficulty ? [item.difficulty] : [])), [solutions]);
  const filtered = useMemo(
    () => filterSolutions(solutions, { query, platform, language, difficulty }),
    [solutions, query, platform, language, difficulty]
  );

  return (
    <div>
      <div className="glass-panel rounded-3xl p-4">
        <div className="grid gap-3 md:grid-cols-[1fr_170px_170px_170px]">
          <input
            value={query}
            onChange={(event) => setQuery(event.target.value)}
            placeholder="Search by title, number, date, platform, or language"
            className="h-12 rounded-2xl border border-emerald-900/10 bg-white px-4 text-sm outline-none transition placeholder:text-ink/35 focus:border-emerald-500 focus:ring-4 focus:ring-emerald-500/10 dark:border-white/10 dark:bg-black/35 dark:text-white dark:placeholder:text-white/35"
          />
          <Select label="Platform" value={platform} onChange={setPlatform} options={platforms} />
          <Select label="Language" value={language} onChange={setLanguage} options={languages} />
          {difficulties.length > 0 && <Select label="Difficulty" value={difficulty} onChange={setDifficulty} options={difficulties} />}
        </div>
      </div>
      <div className="mt-6 flex items-center justify-between px-1 text-sm text-ink/60 dark:text-white/60">
        <span>{filtered.length} solutions found</span>
        {(query || platform || language || difficulty) && (
          <button onClick={() => { setQuery(""); setPlatform(""); setLanguage(""); setDifficulty(""); }} className="font-semibold text-emerald-700 dark:text-emerald-200">
            Clear filters
          </button>
        )}
      </div>
      {filtered.length > 0 ? (
        <div className="mt-5 grid gap-4 sm:grid-cols-2 xl:grid-cols-3">
          {filtered.map((solution) => <SolutionCard key={solution.slug} solution={solution} />)}
        </div>
      ) : (
        <div className="mt-8 rounded-3xl border border-dashed border-emerald-900/20 p-10 text-center dark:border-emerald-300/20">
          <h2 className="text-xl font-semibold text-ink dark:text-white">No matching solutions</h2>
          <p className="mt-2 text-sm text-ink/60 dark:text-white/60">Try a broader search or remove one of the filters.</p>
        </div>
      )}
    </div>
  );
}

function Select({ label, value, onChange, options }: { label: string; value: string; onChange: (value: string) => void; options: string[] }) {
  return (
    <select
      aria-label={label}
      value={value}
      onChange={(event) => onChange(event.target.value)}
      className="h-12 rounded-2xl border border-emerald-900/10 bg-white px-4 text-sm outline-none transition focus:border-emerald-500 focus:ring-4 focus:ring-emerald-500/10 dark:border-white/10 dark:bg-black/35 dark:text-white"
    >
      <option value="">{label}</option>
      {options.map((option) => <option key={option} value={option}>{option}</option>)}
    </select>
  );
}
