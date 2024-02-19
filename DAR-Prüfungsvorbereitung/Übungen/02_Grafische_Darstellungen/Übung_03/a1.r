# Zufallszahlen erzeugen
n <- 50
random <- rnorm(n, mean = 0, sd = 1)
hist(random, freq = FALSE)
lines(seq(min(random), max(random), by=0.01),dnorm(seq(min(random), max(random), by = 0.01), mean = 0, sd = 1), col = "red")
dev.copy(pdf, "a1_1.pdf")
dev.off()

# Layout für verschiedene n
par(mfrow = c(2, 2))
n <- 50
random <- rnorm(n, mean = 0, sd = 1)
hist(random, freq = FALSE, main = paste("n = ", n))
lines(seq(min(random), max(random), by=0.01),dnorm(seq(min(random), max(random), by = 0.01), mean = 0, sd = 1), col = "red")
n <- 100
random <- rnorm(n, mean = 0, sd = 1)
hist(random, freq = FALSE, main = paste("n = ", n))
lines(seq(min(random), max(random), by=0.01),dnorm(seq(min(random), max(random), by = 0.01), mean = 0, sd = 1), col = "red")
n <- 150
random <- rnorm(n, mean = 0, sd = 1)
hist(random, freq = FALSE, main = paste("n = ", n))
lines(seq(min(random), max(random), by=0.01),dnorm(seq(min(random), max(random), by = 0.01), mean = 0, sd = 1), col = "red")
n <- 200
random <- rnorm(n, mean = 0, sd = 1)
hist(random, freq = FALSE, main = paste("n = ", n))
lines(seq(min(random), max(random), by=0.01),dnorm(seq(min(random), max(random), by = 0.01), mean = 0, sd = 1), col = "red")
dev.copy(pdf, "a1_2.pdf")
dev.off()
