"use client";

import Image from "next/image";
import Link from "next/link";
import { usePathname } from "next/navigation";
import { useEffect, useState } from "react";
import { CalendarIcon, CodeIcon, HomeIcon, MenuIcon } from "@/components/Icons";
import { ThemeToggle } from "@/components/ThemeToggle";

const navItems = [
  { href: "/", label: "Home", icon: HomeIcon },
  { href: "/solutions", label: "Solutions", icon: CodeIcon },
  { href: "/calendar", label: "Calendar", icon: CalendarIcon },
  { href: "/leetcode", label: "LeetCode", icon: CodeIcon }
];

export function SiteNav() {
  const pathname = usePathname();
  const [open, setOpen] = useState(false);
  const [expanded, setExpanded] = useState(true);

  useEffect(() => {
    function updateNavSize() {
      setExpanded(window.scrollY <= 120);
    }

    window.requestAnimationFrame(updateNavSize);
    window.addEventListener("scroll", updateNavSize, { passive: true });

    return () => window.removeEventListener("scroll", updateNavSize);
  }, []);

  return (
    <header className="fixed inset-x-0 top-4 z-40 px-4 sm:top-5">
      <nav className={`relative mx-auto grid grid-cols-[auto_1fr_auto] items-center gap-3 rounded-full border border-emerald-400/20 bg-[#07110c]/88 px-3 py-2 shadow-[0_24px_80px_-38px_rgba(16,185,129,0.9)] backdrop-blur-2xl transition-[max-width,padding,background-color,border-color] duration-500 ease-out sm:px-4 ${expanded ? "max-w-6xl" : "max-w-[46rem]"}`}>
        <Link href="/" className="group flex min-w-0 items-center gap-3" onClick={() => setOpen(false)}>
          <span className="grid h-10 w-10 shrink-0 place-items-center overflow-hidden rounded-full border border-emerald-300/25 bg-black shadow-glow">
            <Image src="/GEEKDEVSS_Logo.png" alt="GEEKDEVSS logo" width={44} height={44} className="h-full w-full object-cover" priority />
          </span>
          <span className={`hidden min-w-0 overflow-hidden transition-[max-width,opacity] duration-500 lg:block ${expanded ? "max-w-44 opacity-100" : "max-w-0 opacity-0"}`}>
            <span className="block text-sm font-black tracking-tight text-white">GEEKDEVSS</span>
            <span className="block truncate text-xs text-emerald-100/58">Daily coding archive</span>
          </span>
        </Link>

        <div className="hidden justify-self-center rounded-full border border-white/10 bg-white/[0.06] p-1 shadow-sm md:flex">
          {navItems.map((item) => {
            const active = item.href === "/" ? pathname === "/" : pathname.startsWith(item.href);
            const Icon = item.icon;
            return (
              <Link
                key={item.href}
                className={`inline-flex items-center gap-2 rounded-full py-2 text-sm font-semibold transition-all duration-500 ${expanded ? "px-3.5" : "px-3"} ${active ? "bg-emerald-500 text-[#03140a] shadow-sm" : "text-white/72 hover:bg-white/10 hover:text-white"}`}
                href={item.href}
                title={item.label}
              >
                <Icon className="h-4 w-4" />
                <span className={`overflow-hidden whitespace-nowrap transition-[max-width,opacity] duration-500 ${expanded ? "max-w-24 opacity-100" : "max-w-0 opacity-0"}`}>
                  {item.label}
                </span>
              </Link>
            );
          })}
        </div>

        <div className="flex justify-end gap-2">
          <ThemeToggle />
          <button
            type="button"
            onClick={() => setOpen((value) => !value)}
            aria-expanded={open}
            aria-label="Toggle navigation"
            className="grid h-10 w-10 place-items-center rounded-full border border-white/10 bg-white/[0.06] text-white shadow-sm transition hover:border-emerald-300/40 hover:bg-white/10 md:hidden"
          >
            <MenuIcon className="h-5 w-5" />
          </button>
        </div>

        {open && (
          <div className="absolute left-0 right-0 top-[calc(100%+0.75rem)] grid gap-2 rounded-3xl border border-emerald-300/20 bg-[#07110c]/96 p-2 shadow-glow backdrop-blur-2xl md:hidden">
            {navItems.map((item) => {
              const active = item.href === "/" ? pathname === "/" : pathname.startsWith(item.href);
              const Icon = item.icon;
              return (
                <Link
                  key={item.href}
                  href={item.href}
                  onClick={() => setOpen(false)}
                  className={`inline-flex items-center gap-3 rounded-2xl px-4 py-3 text-sm font-semibold transition ${active ? "bg-emerald-500 text-[#03140a]" : "text-white/72 hover:bg-white/10 hover:text-white"}`}
                >
                  <Icon className="h-4 w-4" />
                  {item.label}
                </Link>
              );
            })}
          </div>
        )}
      </nav>
    </header>
  );
}
