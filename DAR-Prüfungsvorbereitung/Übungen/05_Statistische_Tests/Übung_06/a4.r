# Datensatz einlesen
df <- read.table("teachers3dreich.csv", header = TRUE, sep = ",")

# Gruppieren Sie die Mitgliedschaftszahlen einmal nach Geschlecht und nach Relogion
genderCount <- tapply(df$count, list(df$gender, df$member), FUN = sum)
religionCount <- tapply(df$count, list(df$religion, df$member), FUN = sum)

# Visualisieren Sie die beiden Tabellen mit Spineplot
par(mfrow=c(2,1))
spineplot(genderCount, main="NSDAP-Mitgliedschaft nach Geschlecht", xlab = "Geschlecht", ylab = "Mitgliedscchaft")
spineplot(religionCount, main = "NSDAP-Mitgliedschaft nach Religion", xlab = "Religion", ylab = "Mitgliedschaft")
dev.copy(pdf, "a4.pdf")
dev.off()

print(chisq.test(genderCount))
print(chisq.test(religionCount))
