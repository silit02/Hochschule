fit <- lm(uptake ~ . - Plant, data = CO2)
print(summary(fit))
print(anova(fit))

fit2 <- lm(uptake ~ Treatment + Type + conc + conc:Treatment + conc:Type, data=CO2)
print(summary(fit2))

# Scatterplot uptake vs. conc
plot(uptake ~ conc, data=CO2)

x <- CO2[order(CO2$conc),]

lev_Type <- levels(CO2$Type)
lev_Treat <- levels(CO2$Treatment)
color <- 2

for(i in 1:length(lev_Type)) {
  for(j in 1:length(lev_Treat)) {
    x$Type <- lev_Type[i]
    x$Treatment <- lev_Treat[j]
    y <- predict(fit, x)
    
    lines(y ~ x$conc, col=color)
    color <- color + 1
  }
}

# Legende bauen
legend("bottomright",
       legend=c(paste(lev_Type[1], lev_Treat[1]), paste(lev_Type[1], lev_Treat[2]), paste(lev_Type[2], lev_Treat[1]), paste(lev_Type[2], lev_Treat[2])),
       col=2:5,
       lty=1)

