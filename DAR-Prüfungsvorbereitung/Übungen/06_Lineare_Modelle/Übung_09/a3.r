# Übung 9.3

# Layout festlegen
par(mfrow=c(1,2))

# Boxplot zeichnen
boxplot(breaks ~ wool:tension, data=warpbreaks)

# Dotchart zeichnen
dotchart(warpbreaks$breaks,
         labels=warpbreaks$tension,
         groups=warpbreaks$wool,
         col=as.integer(warpbreaks$tension))

# Modell mit allen Interaktionstermen fitten und ANOVA anwenden
fit <- lm(breaks ~ wool*tension, data=warpbreaks)
print(anova(fit))
