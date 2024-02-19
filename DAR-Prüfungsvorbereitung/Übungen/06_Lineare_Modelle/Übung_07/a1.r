library(gamair)
data(hubble)

# Entfernung in Kilometer umrechnen
data <- hubble
data$km <- data$x * 3.09e19

# Modell fitten
fit <- lm(y ~ 0 + km, data = data)
print(model.matrix(fit))
h0 <- coef(fit)

# Streudiagramm und gefittete Kurve plotten
par(mfrow=c(1,1))
plot(y ~ km, data = data)
abline(fit, col = "red")

# Alter des Universums berechnen
cat(sprintf("Alter des Universums: %.6e Sekunden bzw. %.6e Jahre\n", 1/h0, 1/h0/31536000))
