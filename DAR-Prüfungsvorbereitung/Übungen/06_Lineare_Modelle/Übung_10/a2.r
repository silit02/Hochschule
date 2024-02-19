library(MASS)

# Zufallszahlen erzeugen
n <- 500
x1 <- runif(n, min=3, max=4)
x2 <- runif(n, min=3, max=4)

y <- (4*x1 - 2*x2)^2 + rnorm(n, mean=0, sd=0.01)

# Residuenplot erstellen
par(mfrow=c(2,2))
fit <- lm(y ~ x1 + x2)
scatter.smooth(fit$fitted.values, fit$residuals, lpars=list(col="red"))

## QQ-Plot erstellen
qqnorm(fit$residuals)
qqline(fit$residuals, col="red")

# Box-Cox-Transformation
bc <- boxcox(fit, plotit=F, lambda=seq(-3,3,0.01))
bc.lambda <- bc$x[which.max(bc$y)]
cat(sprintf("Labda Box-Cox: %f", bc.lambda))

# Residuenplot erstellen
yt <- (y^bc.lambda-1)/bc.lambda
fit2 <- lm(yt ~ x1 + x2)
scatter.smooth(fit2$fitted.values, fit2$residuals, lpars=list(col="red"))

## QQ-Plot erstellen
qqnorm(fit2$residuals)
qqline(fit2$residuals, col="red")
