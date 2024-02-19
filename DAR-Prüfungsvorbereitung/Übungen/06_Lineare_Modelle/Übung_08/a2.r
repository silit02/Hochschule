library(GLMsData)
data(heatcap)

for(deg in 3:5) {
  fit <- lm(Cp ~ poly(Temp, deg), data = heatcap)
  print(summary(fit))
}
