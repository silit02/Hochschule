# Space Shuttle O-Rings
orings <- data.frame(ok=factor(c(0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
                                 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1),
                               levels = c(0,1), labels = c("no", "yes")),
                     temp.F=c(53, 57, 58, 63, 66, 67, 67, 67, 68, 69, 70, 70,
                              70, 70, 72, 73, 75, 75, 76, 76, 78, 79, 81))
orings$temp.C <- (orings$temp.F - 32) * 5/9
fit <- glm(ok ~ temp.C, data=orings, family=binomial)

# plotte Daten und Kurve mit Konfidenzbereich
xr <- c(8,28)
n.yes <- sum(orings$ok == "yes")
n.no <- sum(orings$ok == "no")
plot(jitter(orings$temp.C[orings$ok == "yes"]), rep(1, n.yes),
     col="blue", xlim=xr, ylim=c(-0.1,1.1),
     xlab="temp [C]", ylab=NA, type='n')
temp <- seq(xr[1], xr[2], 0.1)

# berechne Konfidenzintervall von Link und transformiere
z <- qnorm(1-0.05/2)
p <- predict(fit, data.frame(temp.C=temp), type="link", se.fit=TRUE)
p.lower <- plogis(p$fit - qnorm(1-0.05/2) * p$se.fit)
p.upper <- plogis(p$fit + qnorm(1-0.05/2) * p$se.fit)

# plotte graues Polygon
polygon(c(temp, rev(temp)), c(p.lower, rev(p.upper)),
        col="#dddddd", border=NA)
lines(temp, predict(fit, data.frame(temp.C=temp), type="response"), col="red")
points(jitter(orings$temp.C[orings$ok == "no"]), rep(0, n.no), col="black")
points(jitter(orings$temp.C[orings$ok == "yes"]), rep(1, n.yes), col="blue")

# cdplot ergänzen
cd <- cdplot(orings$ok ~ orings$temp.C, plot=FALSE)
lines(temp, cd$yes(temp), col="green")

legend("topleft", c("ok = yes","ok = no", "P(Y=1|X=x)", "95% CI", "cd-Plot"),
       col=c("blue","black","red","#dddddd","green"), pch=c(1,1,NA,NA,NA), lty=c(NA,NA,1,1,1), lwd=c(NA,NA,1,10,1))
