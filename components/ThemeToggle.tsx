"use client";

import { useEffect, useState } from "react";
import { MoonIcon, SunIcon } from "@/components/Icons";

export function ThemeToggle() {
  const [isDark, setIsDark] = useState(false);

  useEffect(() => {
    const stored = window.localStorage.getItem("theme");
    const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches;
    const nextDark = stored ? stored === "dark" : prefersDark;
    document.documentElement.classList.toggle("dark", nextDark);
    window.requestAnimationFrame(() => setIsDark(nextDark));
  }, []);

  function toggleTheme() {
    const nextDark = !document.documentElement.classList.contains("dark");
    document.documentElement.classList.toggle("dark", nextDark);
    window.localStorage.setItem("theme", nextDark ? "dark" : "light");
    setIsDark(nextDark);
  }

  return (
    <button
      type="button"
      onClick={toggleTheme}
      aria-label={isDark ? "Switch to light theme" : "Switch to dark theme"}
      title={isDark ? "Light theme" : "Dark theme"}
      className="group relative h-10 w-[4.75rem] rounded-full border border-white/10 bg-white/[0.06] p-1 text-white shadow-sm transition hover:border-emerald-300/40 hover:bg-white/10"
    >
      <span className={`absolute top-1 grid h-8 w-8 place-items-center rounded-full bg-emerald-600 text-white shadow-sm transition-transform ${isDark ? "translate-x-[2.25rem]" : "translate-x-0"}`}>
        {isDark ? <MoonIcon className="h-4 w-4" /> : <SunIcon className="h-4 w-4" />}
      </span>
      <span className="grid h-full grid-cols-2 items-center text-emerald-100/70" aria-hidden="true">
        <SunIcon className="mx-auto h-4 w-4" />
        <MoonIcon className="mx-auto h-4 w-4" />
      </span>
    </button>
  );
}
