# Pakete laden
library(MASS)
library(multimode)

# Von welcher Klasse bzw. Datentyp ist galaxies?
cat("Klasse galaxies: ", class(galaxies), "\nDatentyp galaxies:", typeof(galaxies))

# Korrigieren Sie den in der Doku genannten Fehler.
data <- c(galaxies, 5607)
data[78] <- 26960

# Erstellen Sie drei density-Plots mit default-Bandwidth, einem Viertel (adjust=0.25) davon und dem Vierfachen davon.
plot(density(data, adjust = 0.25), col = "red")
lines(density(data), col = "blue")
lines(density(data, adjust = 4), col = "green")
rug(data)
dev.copy(pdf, "a4_1.pdf")
dev.off()

modetree(data, logbw = TRUE)
dev.copy(pdf, "a4_2.pdf")
dev.off()
