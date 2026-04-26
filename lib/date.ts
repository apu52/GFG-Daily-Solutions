import type { Solution } from "./types";

export function formatDate(date: string) {
  return new Intl.DateTimeFormat("en", {
    month: "short",
    day: "numeric",
    year: "numeric"
  }).format(new Date(`${date}T00:00:00`));
}

export function todayKey() {
  return new Date().toISOString().slice(0, 10);
}

export function getFeaturedSolution(solutions: Solution[], date = todayKey()) {
  const sorted = [...solutions].sort((a, b) => b.date.localeCompare(a.date));
  return sorted.find((solution) => solution.date === date) ?? sorted.find((solution) => solution.date < date) ?? sorted[0];
}

export function groupSolutionsByDate(solutions: Solution[]) {
  return solutions.reduce<Record<string, Solution[]>>((groups, solution) => {
    groups[solution.date] = [...(groups[solution.date] ?? []), solution];
    return groups;
  }, {});
}
