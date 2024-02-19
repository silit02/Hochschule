# Zufallszahlen erzeugen
n <- 500
x1 <- runif(n)
x2 <- runif(n)

sig <- seq(0.1, 2.0, 0.01)

result=data.frame(sigma=numeric(length(sig)), r.squared=numeric(length(sig)))

for(i in 1:length(sig)) {
  y <- 4*x1 - 2*x2 + rnorm(n, mean=0, sd=sig[i])
  
  fit <- lm(y ~ x1 + x2)
  result$r.squared[i] <- summary(fit)$r.squared
  result$sigma[i] <- sig[i]
}

par(mfrow=c(1,2))
scatter.smooth(result$sigma, result$r.squared, ylim=c(0,1), lpars=list(col="red"))

# Mit vergrößerten Daten wiederholen
x1 <- 3*x1
x2 <- 3*x2

result2=data.frame(sigma=numeric(length(sig)), r.squared=numeric(length(sig)))

for(i in 1:length(sig)) {
  y <- 4*x1 - 2*x2 + rnorm(n, mean=0, sd=sig[i])
  
  fit <- lm(y ~ x1 + x2)
  result2$r.squared[i] <- summary(fit)$r.squared
  result2$sigma[i] <- sig[i]
}

scatter.smooth(result2$sigma, result2$r.squared, ylim=c(0,1), lpars=list(col="red"))

mtext("Vergleich R^2", side=3, line=-3, outer=TRUE)
