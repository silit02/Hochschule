# Paket laden
library(GLMsData)
data(lungcap)

fit <- lm(FEV ~ ., data=lungcap)
fit2 <- lm(log(FEV) ~ ., data=lungcap)

cat(sprintf("R^2 Response FEV: %f", summary(fit)$r.squared))
cat(sprintf("\nR^2 Response log(FEV): %f", summary(fit2)$r.squared))

# Daten nach Ht und Age sortieren
x <- lungcap[order(lungcap$Ht, lungcap$Age),]

par(mfrow=c(2,1))

# Streudiagramm plotten
plot(FEV ~ Ht, data=lungcap, main="FEV ~ Ht")
lines(x$Ht, predict(fit, data.frame(Ht=x$Ht, Age=x$Age, Gender=x$Gender, Smoke=x$Smoke)), col="red")

plot(log(FEV) ~ Ht, data=lungcap, main="log(FEV) ~ Ht")
lines(x$Ht, predict(fit2, data.frame(Ht=x$Ht, Age=x$Age, Gender=x$Gender, Smoke=x$Smoke)), col="red")

