# Ausgabe der Gesamtanzahl der Zeilen in airquality
cat("Anzahl der Zeilen im Datensatz airquality:", nrow(airquality), "\n")

# Wie viele NA-Werte enthält der Datensatz insgesamt?
num_na <- sum(is.na(airquality))
cat("Anzahl der NA-Werte im Datensatz airquality:", num_na, "\n")

# Wie viele Zeilen enthalten NA-Werte?
num_na_rows <- sum(rowSums(is.na(airquality)) > 0)
cat("Anzahl Zeilen in airquality, die NA-Werte enthalten:", num_na_rows, "\n")

# Erzeugen Sie einen neuen Datensatz ohne NA-Werte
no_na_rows <- rowSums(is.na(airquality)) == 0
new_dataset <- airquality[no_na_rows, ]

# Was ist der Name der Spalten, die NA-Werte enthalten?
names_airquality <- names(airquality)
na_cols <- colSums(is.na(airquality)) > 0
print(names_airquality[na_cols])
