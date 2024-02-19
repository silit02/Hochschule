# Paket laden
library(HSAUR2)

# Boxplot darstellen
boxplot(mortality ~ ocean, USmelanoma, horizontal = TRUE, main = "Sterblichkeit ocean = yes/no")
dev.copy(pdf, "a4_1.pdf")
dev.off()

# Histogramme darstellen
data <- split(USmelanoma$mortality, USmelanoma$ocean)
par(mfrow=c(2,1))
xrange <- range(USmelanoma$mortality) * c(0.9, 1.1)
hist(data[[1]], main="Histogramm ocean = no", xlim = xrange, xlab="Mortality")
hist(data[[2]], main="Histogramm ocean = yes", xlim = xrange, xlab = "Mortality")
dev.copy(pdf, "a4_2.pdf")
dev.off()