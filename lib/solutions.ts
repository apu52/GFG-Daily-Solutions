import solutionsData from "@/data/solutions.json";
import type { Solution } from "./types";

export function getSolutions() {
  return (solutionsData as Solution[]).sort((a, b) => b.date.localeCompare(a.date) || a.title.localeCompare(b.title));
}

export function getSolutionBySlug(slug: string) {
  return getSolutions().find((solution) => solution.slug === slug);
}

export function getRecentSolutions(limit = 6) {
  return getSolutions().slice(0, limit);
}

export function getSolutionsForDate(date: string) {
  return getSolutions().filter((solution) => solution.date === date);
}
