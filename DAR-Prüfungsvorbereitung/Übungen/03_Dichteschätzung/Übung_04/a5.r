# Datensatz anlegen
temp.F <- c(53,57,58,63,66,67,67,67,68,69,70,70,70,70,72,73,75,75,76,76,78,79,80,81)
fail <- as.factor(c(T,T,T,T,F,F,F,F,F,F,F,F,T,T,F,F,F,T,F,F,F,F,F,F))
data <- data.frame(temp.F, fail)

# Temperatur in Celsius ergänzen
temp.C <- (temp.F - 32)/1.8
data <- cbind(data, temp.C)

# Plot Wahrscheinlichkeit Versagen in Abhänigkeit der Temperatur
cdplot(data$fail ~ data$temp.C, ylab="Failure", xlab="Temperatur C°", main="Spaceshuttle Orings")

# Temperaturen mit Failures einzeichnen
failures <- data[data$fail == TRUE,]
rug(jitter(failures$temp.C), col="red", lwd=1, quiet=TRUE, ticksize=0.1)

# Temperaturen ohne Failure einzeichnen
nonFailures <- data[data$fail == FALSE,]
rug(jitter(nonFailures$temp.C), col="red", lwd=1, quiet=TRUE, side=3, ticksize=0.1)

