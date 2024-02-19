# Paket laden
library(relaimpo)
library(vip)

# Datensatz einlesen
df <- read.table("worldagprod.csv", sep = ",", header = TRUE)

# Modell fitten
min.fit <- lm(Output ~ 1, df)
max.fit <- lm(Output ~ . - Country, df)

# Forward Selection
fit <- step(min.fit, scope=formula(max.fit), direction = "forward", trace=0)

# Aufgabe a)
impo <- calc.relimp(fit, rela=TRUE, type=c("betasq","first","last","lmg"))
result <- data.frame(variable=impo@namen[-1])
for (m in impo@type) { result[m] <- slot(impo, m) }
print(result)

cat("\n")

# Aufgabe b)
impo2 <- vi(fit, method="permute", target="Output",
            metric="rsq_trad", pred_wrapper=predict, 
            nsim=50, sort=FALSE, train=df)
result2 <- as.data.frame(impo2)
print(result2)
