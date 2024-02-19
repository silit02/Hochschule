library(GLMsData)
library(MASS)
data(turbines)

# Visualierung
symbols(turbines$Hours, turbines$Fissures/turbines$Turbines,
        circles=sqrt(turbines$Turbines), inches=0.1, bg="black",
        xlab="Hours", ylab="Proportion of fissures")

# logistische Regression
fit1 <- glm(Fissures/Turbines ~ Hours, weights=Turbines,
            data=turbines, family=binomial)
print(coef(fit1));

x <- seq(0,6000,10)
x_df <- data.frame(Hours=x)

# Plot des Konfidenzintervall ergänzen
p <- predict(fit1, x_df, type="link", se.fit=TRUE)
p.lower <- plogis(p$fit - qnorm(1-0.05/2) * p$se.fit)
p.upper <- plogis(p$fit + qnorm(1-0.05/2) * p$se.fit)
polygon(c(x, rev(x)), c(p.lower, rev(p.upper)), col="#dddddd", border=NA)

# Kreise neu einzeichnen
symbols(turbines$Hours, turbines$Fissures/turbines$Turbines,
        circles=sqrt(turbines$Turbines), inches=0.1, bg="black",
        xlab="Hours", ylab="Proportion of fissures", add=TRUE)

# plotte Kurve ein
lines(x, predict(fit1, x_df, type="response"),
      col="red")

# verschiedene Link-Funktionen ausprobieren
fit2 <- glm(Fissures/Turbines ~ Hours, weights=Turbines,
            data=turbines, family=binomial(link="probit"))
lines(x, predict(fit2, x_df, type="response"), col="blue")

fit3 <- glm(Fissures/Turbines ~ Hours, weights=Turbines,
            data=turbines, family=binomial(link="cauchit"))
lines(x, predict(fit3, x_df, type="response"), col="green")

cat("\nAIC logit:",AIC(fit1),"\n")
cat("AIC probit",AIC(fit2),"\n")
cat("AIC cauchit",AIC(fit3),"\n\n")

# c)
print(dose.p(fit1, cf=1:2, p=0.25))
print(dose.p(fit1, cf=1:2, p=0.5))
print(dose.p(fit1, cf=1:2, p=0.75))
