# Paket laden
library(glmnet)

n <- nrow(attitude)
squared.error <- data.frame(stepwise=numeric(n), lasso=numeric(n))

x <- model.matrix(rating ~ 0 + ., attitude)
y <- attitude$rating

for(i in 1:n) {
  df <- attitude[-i,]
  
  # stepwise regression
  result.stepwise <- step(lm(rating ~ ., df), direction = "backward", trace=0)
  
  # LASSO
  lambda <- cv.glmnet(x[-i,], y[-i], grouped=FALSE)$lambda.min
  lasso <- glmnet(x[-i,], y[-i], lambda=lambda)
  
  # Vorhersagen treffen
  pred.stepwise <- predict(result.stepwise, attitude[i,])
  pred.lasso <- predict(lasso, x[i, ,drop=FALSE])
  
  # Squared Error berechenen
  squared.error[i,"stepwise"] <- abs(attitude[i,"rating"] - pred.stepwise)^2
  squared.error[i,"lasso"] <- abs(attitude[i,"rating"] - pred.lasso)^2
  
}

# mean squared error berechnen
cat("MSE Stepwise Regression: ", mean(squared.error[,"stepwise"]), "\n")
cat("MSE LASSO: ", mean(squared.error[,"lasso"]), "\n")
