import Image from "next/image";
import { notFound } from "next/navigation";
import { BackButton } from "@/components/BackButton";
import { Badge } from "@/components/Badge";
import { CodeBlock } from "@/components/CodeBlock";
import { formatDate } from "@/lib/date";
import { getSolutionBySlug, getSolutions } from "@/lib/solutions";

export function generateStaticParams() {
  return getSolutions().map((solution) => ({ slug: solution.slug }));
}

type SolutionPageProps = {
  params: Promise<{ slug: string }>;
};

export async function generateMetadata({ params }: SolutionPageProps) {
  const { slug } = await params;
  const solution = getSolutionBySlug(slug);
  return {
    title: solution ? `${solution.title} | GEEKDEVSS` : "Solution | GEEKDEVSS"
  };
}

export default async function SolutionDetailPage({ params }: SolutionPageProps) {
  const { slug } = await params;
  const solution = getSolutionBySlug(slug);

  if (!solution) {
    notFound();
  }

  return (
    <div className="mx-auto max-w-7xl px-4 py-10 sm:px-6 lg:px-8">
      <BackButton fallback="/solutions" fallbackLabel="Library" label="Back to library" />
      <div className="grid gap-6 lg:grid-cols-[360px_1fr]">
        <aside className="glass-panel h-fit rounded-3xl p-6">
          <div className="flex flex-wrap gap-2">
            <span className="inline-flex items-center gap-2 rounded-full border border-emerald-500/20 bg-emerald-500/10 px-2.5 py-1 text-xs font-black text-emerald-800 dark:text-emerald-100">
              <Image src="/GEEKDEVSS_Logo.png" alt="" width={18} height={18} className="h-4 w-4 rounded-full object-cover" />
              {solution.platform}
            </span>
            {solution.difficulty && <Badge tone={solution.difficulty}>{solution.difficulty}</Badge>}
          </div>
          <h1 className="mt-5 text-3xl font-semibold tracking-tight text-ink dark:text-white">
            {solution.problemNumber ? `${solution.problemNumber}. ` : ""}
            {solution.title}
          </h1>
          <p className="mt-4 text-sm leading-6 text-ink/62 dark:text-white/62">{solution.summary}</p>
          <dl className="mt-6 space-y-4 text-sm">
            <Meta label="Date" value={formatDate(solution.date)} />
            <Meta label="Language" value={solution.language} />
            <Meta label="File" value={solution.filePath} />
          </dl>
          <a
            href={solution.githubUrl}
            target="_blank"
            rel="noreferrer"
            className="mt-7 inline-flex w-full items-center justify-center rounded-full bg-emerald-600 px-5 py-3 text-sm font-semibold text-white shadow-glow transition hover:bg-emerald-500"
          >
            View on GitHub
          </a>
        </aside>
        <CodeBlock code={solution.code} language={solution.language} fileName={solution.filePath} />
      </div>
    </div>
  );
}

function Meta({ label, value }: { label: string; value: string }) {
  return (
    <div>
      <dt className="font-semibold text-ink dark:text-white">{label}</dt>
      <dd className="mt-1 break-words text-ink/58 dark:text-white/58">{value}</dd>
    </div>
  );
}
