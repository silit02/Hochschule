# Paket laden
library(HSAUR2)

# Modelle fitten
fitAgree <- glm(cbind(agree, disagree) ~ education * gender, data=womensrole, family=binomial)
fitDisagree <- glm(cbind(agree, disagree) ~ education * gender, data=womensrole, family=binomial)

# Signifikanz prüfen
print(anova(fitAgree, test="Chisq"))
print(anova(fitDisagree, test="Chisq"))

# Daten nach Geschlecht aufteilen
male <- womensrole[womensrole$gender == "Male",]
female <- womensrole[womensrole$gender == "Female",]

# Plot Zustimmungswahrscheinlichkeit nach Geschlecht
plot(agree/(agree+disagree) ~ education, data=womensrole, col=womensrole$gender, ylab="Zustimmungswahrscheinlichkeit", main="womensrole")
x <- seq(-1,25,0.1)
lines(x, predict(fitAgree, data.frame(education=x, gender="Male"), type="response"), col=male$gender)
lines(x, predict(fitAgree, data.frame(education=x, gender="Female"), type="response"), col=female$gender)
#legend("topright", legend=c("male", female), col=levels(womensrole$gender))
