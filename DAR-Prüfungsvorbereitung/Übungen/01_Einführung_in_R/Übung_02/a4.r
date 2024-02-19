# Paket laden
library(HSAUR2)

# Wie ist die mittlere Sterberate für ocean = yes/no
res <- aggregate(mortality ~ ocean, data = USmelanoma, FUN = mean)
print(res)

# Was ist fir Korrelation der Sterberate mit Höhen- und Breitengrad?
cat("Korrelation Sterberate mit Breitengrad", cor(USmelanoma$mortality, USmelanoma$latitude), "\n")
cat("Korrelation Sterberate mit Längengrad", cor(USmelanoma$mortality, USmelanoma$longitude), "\n")
