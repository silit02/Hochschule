# Datensatz einlesen
df <- read.table("worldagprod.csv", header = TRUE, sep = ",")

max.fit <- lm(Output ~ . - Country, data = df)

res <- step(max.fit, scope = formula(Output ~ 1, df), direction = "backward")
print(res)
print(summary(res))

# LASSO
library(glmnet)
xx <- model.matrix(Output ~ 0 + . - Country, df)
lambda <- cv.glmnet(xx, df$Output, nfolds=nrow(x), grouped=FALSE)$lambda.min
lasso <- glmnet(xx, df$Output, lambda=lambda)
print(coef(lasso))

