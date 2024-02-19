# Daten einlesen
data <- read.table("covid.csv", header = TRUE, sep = ";")

# Daten für Deutschland herausfiltern
de <- subset(data,data$country == "Germany")

# Plot positive Fälle erstellen
plot(as.Date(de$datum),de$cases,type="l", col="red", xlab="Datum", ylab="Anzahl", main="Entwicklung Covid-19 Deutschland")
lines(as.Date(de$datum),de$hospital_admissions100k*1000, col="blue", type="l")
lines(as.Date(de$datum),de$death, col="orange", type="l")

# Legende erstellen
legend("topleft", legend=c("Positive Testfälle", "Hospitalisierungen pro 100 Millionen Menschen", "Todesfälle"), col=c("red", "blue", "orange"), lty=1)
dev.copy(pdf, "a5.pdf")
dev.off()