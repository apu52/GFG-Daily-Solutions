import { BackButton } from "@/components/BackButton";
import { CalendarExplorer } from "@/components/CalendarExplorer";
import { getSolutions } from "@/lib/solutions";

export const metadata = {
  title: "Calendar | GEEKDEVSS"
};

export default function CalendarPage() {
  return (
    <div className="mx-auto max-w-7xl px-4 py-10 sm:px-6 lg:px-8">
      <BackButton />
      <div className="mb-8">
        <p className="text-sm font-semibold uppercase tracking-[0.22em] text-emerald-700 dark:text-emerald-300">Calendar</p>
        <h1 className="mt-3 text-4xl font-semibold tracking-tight text-ink dark:text-white">Browse by date</h1>
        <p className="mt-3 max-w-2xl text-sm leading-6 text-ink/62 dark:text-white/62">
          Pick a day and view every solution indexed for that date.
        </p>
      </div>
      <CalendarExplorer solutions={getSolutions()} />
    </div>
  );
}
