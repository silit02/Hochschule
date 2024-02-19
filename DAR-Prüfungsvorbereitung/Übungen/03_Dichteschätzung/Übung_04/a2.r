x <- 0
par(mfrow=c(1,1))

# Kernelfunktionen zeichnen
plot(density(x, bw=1, kernel="gaussian"), main="Kernelfunktionen", col="red")
lines(density(x, bw=1, kernel="epanechnikov"), col="blue")
lines(density(x, bw=1, kernel="rectangular"), col="green")
lines(density(x, bw=1, kernel="triangular"), col="lightblue")
lines(density(x, bw=1, kernel="biweight"), col="orange")
lines(density(x, bw=1, kernel="cosine"), col="purple")
lines(density(x, bw=1, kernel="optcosine"), col="pink")

# Legende erstellen
legend("topleft", 
       col=c("red","blue","green","lightblue","orange","purple","pink"),
       legend=c("gaussian", "epanechnikov", "rectangular", "triangular", "biweight","cosine", "optcosine"),
       lty=1
)