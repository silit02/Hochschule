# Äquidistante Zellen im Intervall 1.4 bis 5.3 erzeugen
n <- 25
br <- seq(1.4, 5.3, by=(5.3-1.4)/n)

par(mfrow=c(1,1))
hist(faithful$eruptions, freq = FALSE, breaks = br, xlim = c(1.4,5.3))
dev.copy(pdf, "a1_1.pdf")
dev.off()

par(mfrow=c(2,2))
d <- density(faithful$eruptions, bw = "SJ")
hist(faithful$eruptions, freq = FALSE, breaks = br-0.1, xlim = c(1.4,5.3), ylim = c(0,1), main = "0.1 nach links")
lines(d, col = "red")
hist(faithful$eruptions, freq = FALSE, breaks = br+0.1, xlim = c(1.4,5.3), ylim = c(0,1), main = "0.1 nach rechts")
lines(d, col = "red")
hist(faithful$eruptions, freq = FALSE, breaks = br-0.2, xlim = c(1.4,5.3), ylim = c(0,1), main = "0.2 nach links")
lines(d, col = "red")
hist(faithful$eruptions, freq = FALSE, breaks = br+0.2, xlim = c(1.4,5.3), ylim = c(0,1), main = "0.2 nach rechts")
lines(d, col = "red")
dev.copy(pdf, "a1_2.pdf")
dev.off()