# Normalverteilte Zufallszahlen erzeugen
n <- 50
random <- rnorm(n, mean = 6, sd = 2)

# Plot mit Histogramm, wahrer Dichte, Kerneldichteschätzer und Messpunkten erzeugen
x <- seq(min(random) * 0.9, max(random) * 1.1, by = 0.01)
hist(random, freq = FALSE, ylim = c(0,1), xlim = c(min(random) * 0.9, max(random * 1.1)))
lines(x, dnorm(x, mean = 6, sd = 2), col = "red")
lines(density(random, bw = "SJ", kernel = "gaussian"), col = "blue")
rug(random, col = "orange")
legend("topright", legend = c("wahre Dichte", "Kerneldichteschätzer"), col = c("red","blue"), lty = 1)
