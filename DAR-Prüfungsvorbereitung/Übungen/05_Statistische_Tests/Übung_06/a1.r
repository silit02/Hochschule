library(HSAUR2)

# Kopieren Sie den Datensatz in einen neuen Datensatz, zu dem Sie eine Spalte hinzufügen mit allen Messwerten in Metern.
data <- roomwidth
data$width.metres <- ifelse(data$unit == "feet", data$width/3.28, data$width)

# Stellen Sie die Verteilung der Werte für die Einheiten Feet und Meter in einer Grafik mit zwei Boxplots dar.
par(mfrow=c(1,1))
boxplot(data$width.metres ~ data$unit, ylab = "Schätzung in Meter", xlab = "Einheit")

# Überprüfen Sie, ob der Mittelwert der Schätzungen für die beiden Einheiten signifikant verschieden ist.
print(t.test(width.metres ~ unit, data = data))
