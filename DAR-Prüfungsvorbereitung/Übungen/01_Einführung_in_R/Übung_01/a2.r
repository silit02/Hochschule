library(HSAUR2)
library(HistData)

# Definierte Variablen durch Anzeige der Hilfe herausfinden
# library(help="HSAUR2")
# Verwenden Sie ls() mit pos = 2, um alle Variablen des Pakets zu erhalten
var_HSAUR2 <- ls(pos = "package:HSAUR2")
cat("Variablen des Pakets HSAUR2:",length(var_HSAUR2),"\n")
print(var_HSAUR2)
var_HistData <- ls(pos = "package:HistData")
cat("Variablen des Pakets HistData:",length(var_HistData),"\n")
print(var_HistData)

# Zitierung der Pakete
print(citation("HSAUR2"))
print(citation("HistData"))

print(str(skulls))
