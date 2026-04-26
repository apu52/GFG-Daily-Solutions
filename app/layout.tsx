import type { Metadata } from "next";
import "./globals.css";
import { SiteNav } from "@/components/SiteNav";

export const metadata: Metadata = {
  title: "GEEKDEVSS",
  description: "A searchable, date-based solution library for GEEKDEVSS coding practice.",
  icons: {
    icon: "/GEEKDEVSS_Logo.png",
    shortcut: "/GEEKDEVSS_Logo.png",
    apple: "/GEEKDEVSS_Logo.png"
  }
};

export default function RootLayout({ children }: Readonly<{ children: React.ReactNode }>) {
  return (
    <html lang="en" suppressHydrationWarning>
      <body className="font-sans antialiased">
        <div className="min-h-screen">
          <SiteNav />
          <main className="pt-16 sm:pt-20">{children}</main>
        </div>
      </body>
    </html>
  );
}
