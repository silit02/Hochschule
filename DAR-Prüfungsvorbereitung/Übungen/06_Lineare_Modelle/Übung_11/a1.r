# Datensatz laden
library(GLMsData)
library(boot)
data(heatcap)

# Daten plotten
plot(Cp ~ Temp, data=heatcap, main="Wärmekapazität")

result <- data.frame(Grad=numeric(5), within.MSE=numeric(5), out.MSE=numeric(5), AIC=numeric(5), BIC=numeric(5))
xrange <- range(heatcap$Temp) * c(0.9, 1.1)
x <- seq(xrange[1],xrange[2], by=0.01)

for(deg in 1:5) {
  # Modelle bis Polynom 5. Grades plotten
  fit <- glm(Cp ~ poly(Temp, deg), data=heatcap)
  Cp.pred <- predict(fit, data.frame(Temp=x))
  lines(x, Cp.pred, col=deg+1)
  
  # MSE berechnen
  result[deg, "Grad"] <- deg
  result[deg, "out.MSE"] <- cv.glm(heatcap, fit)$delta[1]
  result[deg, "within.MSE"] <- 1/length(heatcap$Cp)*sum(abs((heatcap$Cp-predict(fit, data.frame(Temp=heatcap$Temp))))^2)
  
  # AIC und BIC berechnen (Aufgabe a)
  result[deg, "AIC"] <- AIC(fit)
  result[deg, "BIC"] <- BIC(fit)
}

# Legende hinzufügen
legend("topleft", legend=c("Grad 1", "Grad 2", "Grad 3", "Grad 4", "Grad 5"), col=c(2,3,4,5,6), lty=1)

# Ergebnis ausgeben
print(result)

# model.matrix vom Grad 5 erzeugen und Koeffizienten einer LASSO-Regression ermitteln
# LASSO
library(glmnet)
x <- model.matrix(Cp ~ 0 + poly(Temp,5), heatcap)
lambda <- cv.glmnet(x, heatcap$Cp, nfolds=nrow(x), grouped=FALSE)$lambda.min
lasso <- glmnet(x, heatcap$Cp, lambda=lambda)
print(coef(lasso))
