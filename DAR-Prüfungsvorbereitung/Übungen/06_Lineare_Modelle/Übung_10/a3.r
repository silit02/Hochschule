# Paket laden
library(MASS)

# Modell fitten
fit1 <- lm(1+Days ~ .^3, quine)

# Box-Cox-Transformation
bc <- boxcox(fit1, plotit=F, lambda=seq(-3,3,0.01))
bc.lambda <- bc$x[which.max(bc$y)]
cat(sprintf("Labda Box-Cox: %f", bc.lambda))

par(mfrow=c(2,2))

# Residual-Plot
scatter.smooth(fit1$fitted.values, fit1$residuals, lpars=list(col="red"))

## QQ-Plot erstellen
qqnorm(fit1$residuals)
qqline(fit1$residuals, col="red")

# Transformation durchführen
fit2 <- lm(((1+Days)^bc.lambda-1)/bc.lambda ~ .^3, quine)

# Residual-Plot
scatter.smooth(fit2$fitted.values, fit2$residuals, lpars=list(col="red"))

## QQ-Plot erstellen
qqnorm(fit2$residuals)
qqline(fit2$residuals, col="red")
