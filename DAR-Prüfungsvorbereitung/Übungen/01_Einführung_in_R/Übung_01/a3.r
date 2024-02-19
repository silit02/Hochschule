# a)
a <- c(1, 2, 3)
b <- c(3, 2, 1)
cat("a <- c(1,2,3)\nb <- c(3,2,1)\n")
cat("a*b =", a * b, "\n") # Elementweise Multiplikation
cat("a%*%b =", a %*% b, "\n") # Skalarprodukt
cat("a>b =", a > b, "\n") # Elementweiser vergleich

# b)
cat("a%o%b =", a %o% b, "\n") # Outer Product (a_ij = x_i * y_j)
