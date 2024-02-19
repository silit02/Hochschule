# Paket laden
library(HistData)

# Pumpen plotten
plot(Snow.pumps$x, Snow.pumps$y,
     col = "red", xlim = range(Snow.pumps$x),
     ylim = range(Snow.pumps$y), xlab = "x", ylab = "y",
     main = "Snow-Datensatz")

# Tote einzeichnen
points(Snow.deaths$x, Snow.deaths$y, col = "black", pch = 4)

# Polygonränder einzeichnen
for (polygon in Snow.polygons) {
     polygon(polygon, border = "blue")
}

# Legende erstellen
legend("topright", c("Wasserpumpen","Tote"), col=c("red","black"), pch=c(1,4))

# identify
identify(Snow.pumps$x, Snow.pumps$y, col="red", labels=Snow.pumps$label)
