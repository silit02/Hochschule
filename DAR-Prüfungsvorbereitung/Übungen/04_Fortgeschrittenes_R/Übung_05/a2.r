library(microbenchmark)

ReLU <- function(x) {
  if (x > 0) {
    return(x)
  } else {
    return(0) }
}

ReLU_v1 <- function(x) {
  return(ifelse(x > 0, x, 0))
}

ReLU_v2 <- function(x) {
  return(x * (x > 0))
}

x <- -10000:10000
print(microbenchmark(ReLU_v1(x), ReLU_v2(x), check = "equal"))

# Funktionen plotten
par(mfrow=c(2,1))
plot(x, ReLU_v1(x), type="l", col="blue", main="ReLU_ifelse")
plot(x, ReLU_v2(x), type="l", col="red", main="ReLU_mult")
