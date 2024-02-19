library(MASS)
data(whiteside)

# Messwerte Scatterplot
plot(Gas ~ Temp, data = whiteside, col = Insul)
legend("topright", legend = c("Before", "After"), col = as.integer(unique(whiteside$Insul)), pch = 1)

before <- subset(whiteside, whiteside$Insul == "Before")
after <- subset(whiteside, whiteside$Insul == "After")

fit.before <- lm(Gas ~ Temp, data = before)
fit.after <- lm(Gas ~ Temp, data = after)

abline(fit.before, col = as.integer(before$Insul))
abline(fit.after, col = as.integer(after$Insul))

print(coef(fit.before))
print(coef(fit.after))

# quadratischen Fit für After einzeichnen
fit2 <- lm(Gas ~ poly(Temp, 2), data=after)
x <- seq(range(whiteside$Temp)[1], range(whiteside$Temp)[2], by=0.01)
lines(x,predict(fit2, data.frame(Temp=x)), col="orange")

# LOESS-Fit für After einzeichnen
lines(loess.smooth(after$Temp, after$Gas), col="purple")

# Zweite Legende hinzufügen
legend("bottomleft",
       legend=c("Lineares Modell Before", "Lineares Modell After", "Quadratisches Modell After", "LOESS-Fit After"), 
       col=c(unique(as.integer(whiteside$Insul)),"orange", "purple"), 
       lty=1)


