export type Platform = "GEEKDEVSS" | "LeetCode" | "Other";
export type Difficulty = "Easy" | "Medium" | "Hard";

export type Solution = {
  slug: string;
  title: string;
  date: string;
  platform: Platform;
  difficulty?: Difficulty;
  language: string;
  extension: string;
  filePath: string;
  githubUrl: string;
  problemNumber?: string;
  summary: string;
  code: string;
};

export type SolutionFilters = {
  query?: string;
  platform?: string;
  language?: string;
  difficulty?: string;
};
