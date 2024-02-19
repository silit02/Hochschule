# Tabelle mit Überlebensstatus versus Klasse
table <- apply(Titanic, MARGIN = c("Survived", "Class"), FUN = sum)
print(table)

# Daten in Barplot darstellen
par(mfrow=c(2, 2))
barplot(table, xlab = "Class", ylab = "Survived", legend.text = TRUE, args.legend=list(x="topleft"))
barplot(t(table), xlab = "Survived", ylab = "Class", legend.text = TRUE, args.legend=list(x="topright"))
barplot(table, xlab = "Class", ylab = "Survived", legend.text = TRUE, args.legend=list(x="topleft"), beside = TRUE)
barplot(t(table), xlab = "Survived", ylab = "Class", legend.text = TRUE, args.legend=list(x="topright"), beside = TRUE)
dev.copy(pdf, "a3_1.pdf", width = 8, height = 8)
dev.off()

# Daten in einem Spineplot darstellen
par(mfrow=c(1,1))
spineplot(table)
dev.copy(pdf, "a3_2.pdf")
dev.off()

