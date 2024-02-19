# Paket laden
library(gamair)
data(hubble)

# Geschwindigkeit in Kilometern pro Sekunde
v <- hubble$y

# Entfernung in Kilometern
d <- hubble$x * 3.09e19

# Modell fitten
fit <- lm(v ~ 0 + d)

# Modell-Matrix ausgeben
print(model.matrix(fit))

# Streudiagramm und Kurve des gefitteten Modells plotten
plot(v ~ d, col="blue", main="Streudiagramm", xlab="Entfernung in km", ylab="Geschwindigkeit in km/s")
lines(d, predict(fit, list(d)), col="red")
legend("topleft", legend=c("Messwerte", "Modell"), col=c("blue", "red"), lty=1)

# Alter des Universums berechnen
h0 <- coef(fit)
cat(sprintf("\nAlter des Universums: %.6e Sekunden bzw. %.6e Jahre\n", 1/h0, (1/h0)/31536000))

# Konfidenzintervall bestimmen
int <- confint(fit, level=0.95)
int <- 1/int

# Umrechnung in Jahre
int <- int/31536000

# Ausgabe Ergebnis
cat("Konfidenzintervall für Alter des Universums:\n")
print(int)
cat(sprintf("%.6e %.6e",int[2],int[1]))
