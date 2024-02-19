#
# Übung 9.1: Simulation eines Modells y ~ x1*x3
#

N <- 5000
df <- data.frame(x1=runif(N,min=1, max=2),
                 x2=runif(N,min=0,max=1),
                 x3=factor(sample(c("yes","no"), replace=T, N)))
df$y <- rnorm(N, mean=0, sd=0.5) + 4*df$x1 +
  ifelse(df$x3 == "yes", 3, 1) +
  ifelse(df$x3 == "yes", 0, df$x1)
