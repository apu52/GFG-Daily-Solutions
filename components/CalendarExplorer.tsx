"use client";

import { useMemo, useState } from "react";
import { ArrowLeftIcon, ArrowRightIcon } from "@/components/Icons";
import { SolutionCard } from "@/components/SolutionCard";
import { groupSolutionsByDate, todayKey } from "@/lib/date";
import type { Solution } from "@/lib/types";

export function CalendarExplorer({ solutions }: { solutions: Solution[] }) {
  const grouped = useMemo(() => groupSolutionsByDate(solutions), [solutions]);
  const [selectedDate, setSelectedDate] = useState(todayKey());
  const [visibleMonth, setVisibleMonth] = useState(selectedDate.slice(0, 7));
  const matches = grouped[selectedDate] ?? [];
  const days = useMemo(() => buildMonthDays(visibleMonth), [visibleMonth]);

  function moveMonth(offset: number) {
    const [year, month] = visibleMonth.split("-").map(Number);
    const date = new Date(year, month - 1 + offset, 1);
    setVisibleMonth(`${date.getFullYear()}-${String(date.getMonth() + 1).padStart(2, "0")}`);
  }

  return (
    <div className="grid gap-6 lg:grid-cols-[390px_1fr]">
      <aside className="glass-panel h-fit rounded-3xl p-5">
        <div className="flex items-center justify-between">
          <div>
            <p className="text-xs font-semibold uppercase tracking-[0.22em] text-emerald-700 dark:text-emerald-300">Calendar</p>
            <h2 className="mt-1 text-2xl font-semibold tracking-tight text-ink dark:text-white">{monthLabel(visibleMonth)}</h2>
          </div>
          <div className="flex gap-2">
            <button type="button" onClick={() => moveMonth(-1)} className="grid h-10 w-10 place-items-center rounded-full border border-emerald-900/10 bg-white/70 font-semibold text-ink transition hover:bg-emerald-50 dark:border-white/10 dark:bg-white/5 dark:text-white dark:hover:bg-emerald-400/10" aria-label="Previous month">
              <ArrowLeftIcon className="h-4 w-4" />
            </button>
            <button type="button" onClick={() => moveMonth(1)} className="grid h-10 w-10 place-items-center rounded-full border border-emerald-900/10 bg-white/70 font-semibold text-ink transition hover:bg-emerald-50 dark:border-white/10 dark:bg-white/5 dark:text-white dark:hover:bg-emerald-400/10" aria-label="Next month">
              <ArrowRightIcon className="h-4 w-4" />
            </button>
          </div>
        </div>

        <div className="mt-5 grid grid-cols-7 gap-2 text-center text-xs font-semibold text-ink/45 dark:text-white/45">
          {["S", "M", "T", "W", "T", "F", "S"].map((day) => <span key={day}>{day}</span>)}
        </div>
        <div className="mt-2 grid grid-cols-7 gap-2">
          {days.map((day, index) => {
            const count = day ? (grouped[day]?.length ?? 0) : 0;
            const isSelected = day === selectedDate;
            return day ? (
              <button
                key={day}
                type="button"
                onClick={() => setSelectedDate(day)}
                className={`relative aspect-square rounded-2xl border text-sm font-semibold transition ${isSelected ? "border-emerald-400 bg-emerald-600 text-white shadow-glow" : count > 0 ? "border-emerald-500/25 bg-emerald-500/10 text-emerald-800 hover:bg-emerald-500/20 dark:text-emerald-100" : "border-emerald-900/10 bg-white/45 text-ink/45 hover:bg-white dark:border-white/10 dark:bg-white/[0.03] dark:text-white/35"}`}
              >
                {Number(day.slice(-2))}
                {count > 0 && <span className="absolute bottom-1 left-1/2 h-1 w-1 -translate-x-1/2 rounded-full bg-current" />}
              </button>
            ) : (
              <span key={`empty-${index}`} />
            );
          })}
        </div>

        <div className="mt-5 rounded-3xl border border-emerald-400/20 bg-gradient-to-br from-emerald-500 to-green-900 p-5 text-white">
          <p className="text-sm text-white/75">Selected day</p>
          <p className="mt-1 text-2xl font-semibold tracking-tight">{selectedDate}</p>
          <p className="mt-4 text-sm text-white/80">{matches.length || "No"} solution{matches.length === 1 ? "" : "s"} found</p>
        </div>
      </aside>
      <section>
        {matches.length > 0 ? (
          <div className="grid gap-4 md:grid-cols-2">
            {matches.map((solution) => <SolutionCard key={solution.slug} solution={solution} />)}
          </div>
        ) : (
          <div className="glass-panel rounded-3xl p-10 text-center">
            <h2 className="text-xl font-semibold text-ink dark:text-white">No solution for this date</h2>
            <p className="mt-2 text-sm text-ink/60 dark:text-white/60">Choose another day or browse the complete archive.</p>
          </div>
        )}
      </section>
    </div>
  );
}

function buildMonthDays(monthKey: string) {
  const [year, month] = monthKey.split("-").map(Number);
  const first = new Date(year, month - 1, 1);
  const total = new Date(year, month, 0).getDate();
  const blanks = Array.from<string | null>({ length: first.getDay() }).fill(null);
  const days = Array.from({ length: total }, (_, index) => `${monthKey}-${String(index + 1).padStart(2, "0")}`);
  return [...blanks, ...days];
}

function monthLabel(monthKey: string) {
  return new Intl.DateTimeFormat("en", { month: "long", year: "numeric" }).format(new Date(`${monthKey}-01T00:00:00`));
}
