# Paket laden
library(microbenchmark)

# je Spalte die Summe der Werte berechnen
s.loop <- function(x) {
  n <- ncol(x)
  sums <- numeric(n)
  for(i in 1:n) {
    sums[i] <- sum(x[,i])
  }  
  return(sums)
}

s.apply <- function(x) {
  return(apply(x, MARGIN = 2, FUN = sum))
}

# zufällige 100x100 Matrix erstellen
m <- matrix(runif(100*100), nrow=100, ncol=100)

# Laufzeit mittels microbenchmark vergleichen
print(microbenchmark(s.loop(m), s.apply(m), colSums(m), check="equal"))
