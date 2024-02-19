source("ueb09.1.r")

fit1 <- lm(y ~ ., data = df)
print(summary(fit1))
print(anova(fit1))
print(drop1(fit1))

# Komplettes Modell fitten
fit2 <- lm(y ~ x1*x2*x3, data = df)
print(summary(fit2))

# Wie ändert sich R^2, wenn sie x2 weglassen
fit3 <- lm(y ~ x1*x3, data = df)
print(summary(fit3)$r.squared)

