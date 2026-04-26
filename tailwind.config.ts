import type { Config } from "tailwindcss";

const config: Config = {
  darkMode: "class",
  content: [
    "./app/**/*.{ts,tsx}",
    "./components/**/*.{ts,tsx}",
    "./lib/**/*.{ts,tsx}"
  ],
  theme: {
    extend: {
      colors: {
        ink: "#07110c",
        moss: "#0f6f3d",
        mint: "#32d583",
        leaf: "#16a34a"
      },
      boxShadow: {
        glow: "0 24px 80px -36px rgba(22, 163, 74, 0.7)"
      }
    }
  },
  plugins: []
};

export default config;
