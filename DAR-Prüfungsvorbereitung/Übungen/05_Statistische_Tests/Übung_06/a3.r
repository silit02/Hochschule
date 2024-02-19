par(mfrow=c(2,1))

# Stellen Sie die Gewichtsverteilung für die drei Gruppen in einem Boxplot dar
boxplot(weight ~ group, data = PlantGrowth, horizontal = TRUE)

# Daten nach Gruppen aufteilen
ctrlGroup <- PlantGrowth[PlantGrowth$group == "ctrl",] 
trt1Group <- PlantGrowth[PlantGrowth$group == "trt1",] 
trt2Group <- PlantGrowth[PlantGrowth$group == "trt2",] 

# Dichten berechnen
ctrlDensity <- density(ctrlGroup$weight)
trt1Density <- density(trt1Group$weight, bw=ctrlDensity$bw)
trt2Density <- density(trt2Group$weight, bw=ctrlDensity$bw)

# Bereich Achsen bestimmen
xrange = c(min(range(ctrlDensity$x), range(trt1Density$x), range(trt2Density$x)), max(range(ctrlDensity$x), range(trt1Density$x), range(trt2Density$x)))
yrange = c(min(range(ctrlDensity$y), range(trt1Density$y), range(trt2Density$y)), max(range(ctrlDensity$y), range(trt1Density$y), range(trt2Density$y)))

# Plot zeichnen
plot(ctrlDensity, col=as.integer(ctrlGroup$group), main="Density-Plot nach Gruppen", xlim=xrange, ylim=yrange)
lines(trt1Density, col=as.integer(trt1Group$group))
lines(trt2Density, col=as.integer(trt2Group$group))

# Legende hinzufügen
legend("topleft",legend=c("ctrl","trt1","trt2"), col=c(as.integer(ctrlGroup$group[1]), as.integer(trt1Group$group[1]), as.integer(trt2Group$group[1])), lty=1)

# ANOVA anwenden
res <- aov(weight ~ group, data = PlantGrowth)
print(anova(res))

# pairwise.t.test durchführen
print(pairwise.t.test(PlantGrowth$weight, PlantGrowth$group))
