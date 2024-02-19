df <- read.table("covid.csv", header = TRUE, sep = ";")
df$datum <- as.Date(df$datum)

# Daten für Deutschland herausfiltern
df_ger <- subset(df, df$country == "Germany")

# In welcher Woche verzeichnen die Spalten death, cases und hospital_admissions100k für Deutschland ihre Höchstwerte?
max.death <- which.max(df_ger$death)
max.cases <- which.max(df_ger$cases)
max.hospital <- which.max(df_ger$hospital_admissions100k)

cat("Maximum Todesfälle in Woche", as.character(df_ger[max.death, "datum"]), "mit", df_ger[max.death, "death"], "Fällen\n")
cat("Maximum positive Testfälle in Woche", as.character(df_ger[max.cases, "datum"]), "mit", df_ger[max.cases, "cases"], "Fällen\n")
cat("Maximum Hospitalisierungen in Woche", as.character(df_ger[max.hospital, "datum"]), "mit", df_ger[max.hospital, "hospital_admissions100k"], "Fällen pro 100k\n")

# Wann und was waren die Höchstwerte vor 08/2020?
cat("\nDaten vor 2020-08-01:\n")
enddatum <- as.Date("2020-08-01")
df_ger_early <- subset(df_ger, df_ger$datum < enddatum)

max.death <- which.max(df_ger_early$death)
max.cases <- which.max(df_ger_early$cases)
max.hospital <- which.max(df_ger_early$hospital_admissions100k)

cat("Maximum Todesfälle in Woche", as.character(df_ger_early[max.death, "datum"]), "mit", df_ger_early[max.death, "death"], "Fällen\n")
cat("Maximum positive Testfälle in Woche", as.character(df_ger_early[max.cases, "datum"]), "mit", df_ger_early[max.cases, "cases"], "Fällen\n")
cat("Maximum Hospitalisierungen in Woche", as.character(df_ger_early[max.hospital, "datum"]), "mit", df_ger_early[max.hospital, "hospital_admissions100k"], "Fällen pro 100k\n")
