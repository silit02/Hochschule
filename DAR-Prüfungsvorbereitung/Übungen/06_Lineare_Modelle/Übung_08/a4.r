# Paket und Datensatz laden
library(GLMsData)
data(nhospital)

# Modell mit allen Variablen fitten
fit <- lm(MainHours ~ ., data=nhospital)
print(summary(fit))

# einzeln fitten
fit_Cases <- lm(MainHours ~ Cases, data=nhospital)
print(summary(fit_Cases))

fit_Eligible <- lm(MainHours ~ Eligible, data=nhospital)
print(summary(fit_Eligible))

fit_OpRooms <- lm(MainHours ~ OpRooms, data=nhospital)
print(summary(fit_OpRooms))

# Korrelationsmatrix und Scatterplots
print(cor(nhospital))
pairs(nhospital)
