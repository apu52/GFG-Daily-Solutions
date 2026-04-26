import Link from "next/link";

export default function NotFound() {
  return (
    <section className="mx-auto flex min-h-[70vh] max-w-3xl flex-col items-center justify-center px-6 text-center">
      <p className="mb-3 text-sm font-semibold uppercase tracking-[0.25em] text-emerald-600">404</p>
      <h1 className="text-4xl font-semibold tracking-tight text-ink dark:text-white">Solution not found</h1>
      <p className="mt-4 max-w-xl text-ink/65 dark:text-white/65">
        This entry is not in the generated manifest yet. Regenerate `data/solutions.json` after adding new files.
      </p>
      <Link href="/solutions" className="mt-8 rounded-full bg-emerald-600 px-5 py-3 text-sm font-semibold text-white shadow-glow transition hover:bg-emerald-500">
        Browse library
      </Link>
    </section>
  );
}
