# Finden Sie heraus, welche Daten er erthält und was sie bedeuten.
# Sepal.Length: num
# Sepal.Width : num
# Petal.Length: num
# Petal.Width : num
# Species     : Factor w/ 3 levels "setosa","versicolor",...

# Berechnen Sie für jede numerische Spalte Mittelwert und Standardabweichung.
cat("Sepal.Length: Mittelwert:", mean(iris$Sepal.Length),
    ", Standardabweichung:", sd(iris$Sepal.Length), "\n")
cat("Sepal.Width: Mittelwert:", mean(iris$Sepal.Width),
    ", Standardabweichung:", sd(iris$Sepal.Width), "\n")
cat("Petal.Length: Mittelwert:", mean(iris$Petal.Length),
    ", Standardabweichung:", sd(iris$Petal.Length), "\n")
cat("Petal.Width: Mittelwert:", mean(iris$Petal.Width),
    ", Standardabweichung:", sd(iris$Petal.Width), "\n")

# Ergebnisse in Data Frame speichern
data <- data.frame(Species=levels(iris$Species), Sepal.Length=character(3), Sepal.Width=character(3), Petal.Length=character(3), Petal.Width=character(3))

#Mittelwert und Standardabweichung pro Spezies berechnen
means <- aggregate(iris[,-5], by=list(iris$Species), FUN=mean)
sds <- aggregate(iris[,-5], by=list(iris$Species), FUN=sd)

# Werte in neuen DataFrame Kopieren
data["Sepal.Length"] <- sprintf("%.2f +- %.2f", means$Sepal.Length, sds$Sepal.Length)
data["Sepal.Width"] <- sprintf("%.2f +- %.2f", means$Sepal.Width, sds$Sepal.Width)
data["Petal.Length"] <- sprintf("%.2f +- %.2f", means$Petal.Length, sds$Petal.Length)
data["Petal.Width"] <- sprintf("%.2f +- %.2f", means$Petal.Width, sds$Petal.Width)

print(data)
