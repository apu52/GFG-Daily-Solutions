import type { Difficulty } from "@/lib/types";

const difficultyTone: Record<Difficulty, string> = {
  Easy: "border-emerald-500/30 bg-emerald-500/10 text-emerald-700 dark:text-emerald-200",
  Medium: "border-lime-500/30 bg-lime-500/10 text-lime-700 dark:text-lime-200",
  Hard: "border-rose-500/30 bg-rose-500/10 text-rose-700 dark:text-rose-200"
};

export function Badge({ children, tone }: { children: React.ReactNode; tone?: Difficulty }) {
  return (
    <span className={`inline-flex items-center rounded-full border px-2.5 py-1 text-xs font-semibold ${tone ? difficultyTone[tone] : "border-emerald-500/20 bg-emerald-500/10 text-emerald-700 dark:text-emerald-200"}`}>
      {children}
    </span>
  );
}
