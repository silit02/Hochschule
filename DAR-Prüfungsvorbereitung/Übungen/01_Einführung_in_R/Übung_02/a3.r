# Von welchem Datentyp ist der Datensatz? Wie viel-dimensional ist er?
print(str(Titanic))

# Was ist der Anteil Überlebender an allen Personen?
cat("\nGesamtzahl Überlebender\n")
sur <- apply(Titanic, "Survived", sum)
print(sur)
cat(sprintf("Anteil Überlebender: %f\n", sur[2] / sur[1]))

# Wie ist der Anteil Überlebender je Passagierklasse?
# Gesamtzahl überlebender je Passagierklasse
cat("\nGesamtzahl Überlebender je Passagierklasse\n")
sur <- apply(Titanic, MAR = c("Class", "Survived"), sum)
print(sur)

# Anteil der Überlebenden nach Passagierklasse
cat("\nAnteil Überlebender pro Passagierklasse:\n")
print(sur / rowSums(sur))
