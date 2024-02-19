# Paket laden
library(HSAUR2)

# Welche Spalten enthält er? Welcher Datentyp?
print(str(USmelanoma))

# Wie viele Datensätze enthält der Datensatz?
print(nrow(USmelanoma))

# Zeigen Sie die ersten 5 Zeilen an.
print(head(USmelanoma, 5))

# US-Bundesstaat als Name der Zeile gespeichert.
# Zeile für den Bundesstaat Ohio:
print(USmelanoma["Ohio", ])
