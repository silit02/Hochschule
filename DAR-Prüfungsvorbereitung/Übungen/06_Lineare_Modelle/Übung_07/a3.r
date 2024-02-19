# Datensatz laden
library(GLMsData)
library(boot)
data(heatcap)

# Daten plotten
plot(Cp ~ Temp, data=heatcap, main="Wärmekapazität")

result <- data.frame(Grad=numeric(5), within.MSE=numeric(5), out.MSE=numeric(5))

for(deg in 1:5) {
  # Modelle bis Polynom 5. Grades plotten
  fit <- glm(Cp ~ poly(Temp, deg), data=heatcap)
  xrange <- range(heatcap$Temp) * c(0.9, 1.1)
  x <- seq(xrange[1],xrange[2], by=0.01)
  Cp.pred <- predict(fit, data.frame(Temp=x))
  lines(x, Cp.pred, col=deg+1)
  
  # MSE berechnen
  result[deg, "Grad"] <- deg
  result[deg, "out.MSE"] <- cv.glm(heatcap, fit)$delta[1]
  result[deg, "within.MSE"] <- 1/length(heatcap$Cp)*sum(abs((heatcap$Cp-predict(fit, data.frame(Temp=heatcap$Temp))))^2)
}

# Legende hinzufügen
legend("topleft", legend=c("Grad 1", "Grad 2", "Grad 3", "Grad 4", "Grad 5"), col=c(2,3,4,5,6), lty=1)

# Ergebnis ausgeben
print(result)
