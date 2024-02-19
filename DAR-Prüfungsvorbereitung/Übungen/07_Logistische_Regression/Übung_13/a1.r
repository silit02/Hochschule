# Daten einlesen
resect <- read.table("resect.csv", sep = ",", header = TRUE)

# Modelle fitten
fit4 <- glm(died ~ age + prior + resection + intubated, data=resect, family="binomial")
fit1 <- glm(died ~ resection, data=resect, family="binomial")
fit2 <- glm(died ~ resection + intubated, data=resect, family="binomial")

# a)
# Signifikante Variablen in fit4
print(summary(fit4))
print(anova(fit4, test="Chisq"))
print(drop1(fit4, test="Chisq"))

# b)
# Verlauf Wahrscheinlichkeiten fit2 plotten
par(mfrow=c(2,1))
x <- seq(0,6,0.1)
res_intubated <- resect[resect$intubated == 1,]
res_nonintubated <- resect[resect$intubated == 0,]
plot(jitter(died, factor=0.1) ~ resection, data=resect, col=resect$intubated+1)
lines(x, predict(fit2, data.frame(resection=x, intubated=1), type="response"), col=res_intubated$intubated+1)
lines(x, predict(fit2, data.frame(resection=x, intubated=0), type="response"), col=res_nonintubated$intubated+1)
legend("right", legend=c("nonintubated", "intubated"), col=c(1,2), pch=1)

# c) 
# Confusion Matrix für alle drei Modelle berechnen (in-sample und leave-one-out)
for(fit in list(fit4, fit1, fit2)) {
  
  cat("\n",deparse(formula(fit)),"\n")
  
  # in-sample
  cat("in-sample\n")
  pred.fit <- predict(fit, resect, type="response")
  pred.fit <- ifelse(pred.fit >= 0.5, 1, 0)
  print(table(resect$died, pred.fit))
  cat("error rate:",mean(resect$died != pred.fit))
  
  # leave-one-out
  cat("\nleave-one-out\n")
  pred.loo <- resect$died
  for(i in 1:nrow(resect)) {
    fit.i <- glm(fit$formula, resect[-i,], family="binomial")
    prob.i <- predict(fit.i, resect[i,], type="response")
    pred.loo[i] <- ifelse(prob.i >= 0.5, 1, 0)
  }
  print(table(resect$died, pred.loo))
  cat("error rate:",mean(resect$died != pred.loo), "\n")
  
}

# d)
plot(NA, type="n", ylim=c(0,1), xlim=c(1,0), xlab=NA, ylab=NA)
library(pROC)
col <- 1
for(fit in list(fit4, fit1, fit2)) {
  probs <- predict(fit, resect, type="response")
  r <- roc(resect$died, probs, levels=c(0,1))
  plot(r, asp=NA, add=TRUE, col=col)
  cat("AUC",deparse(formula(fit)),":",r$auc,"\n")
  col <- col+1
}
legend("right", legend=c("ROC fit4", "ROC fit1", "ROC fit2"), col=c(1,2,3), lty=1)
