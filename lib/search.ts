import type { Solution, SolutionFilters } from "./types";

export function uniqueSorted(values: string[]) {
  return Array.from(new Set(values.filter(Boolean))).sort((a, b) => a.localeCompare(b));
}

export function filterSolutions(solutions: Solution[], filters: SolutionFilters) {
  const query = filters.query?.trim().toLowerCase();

  return solutions.filter((solution) => {
    const haystack = [
      solution.title,
      solution.problemNumber,
      solution.platform,
      solution.language,
      solution.date,
      solution.difficulty,
      solution.summary
    ]
      .filter(Boolean)
      .join(" ")
      .toLowerCase();

    const matchesQuery = query ? haystack.includes(query) : true;
    const matchesPlatform = filters.platform ? solution.platform === filters.platform : true;
    const matchesLanguage = filters.language ? solution.language === filters.language : true;
    const matchesDifficulty = filters.difficulty ? solution.difficulty === filters.difficulty : true;

    return matchesQuery && matchesPlatform && matchesLanguage && matchesDifficulty;
  });
}
