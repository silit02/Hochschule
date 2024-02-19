# Welche Variablen haben signifikanten Einfluss auf die Gesamtbewertung rating?
fit <- lm(rating ~ ., data = attitude)
print(summary(fit))

# --> complaints und learning

# Fitten Sie ein Modell mit diesen Variablen und plotten Sie rating als Funktion
# der einflussreichsten Variable sowie den Fit des Modells mit dieser Variablen
# und der zweit signifikantesten.
fit <- lm(rating ~ complaints + learning, data = attitude)
plot(rating ~ complaints, data = attitude)

sorted_by_complaints <- attitude[order(attitude$complaints, attitude$learning),]
lines(sorted_by_complaints$complaints, predict(fit, sorted_by_complaints), col = "red")
