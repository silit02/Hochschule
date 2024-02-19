# Gleichungssystem:
# x1 + 2x2 = 2
# 3x1 - x2 = 0
a <- matrix(c(1, 2, 3, -1), nrow = 2, ncol = 2, byrow = TRUE)
b <- c(2, 0)
res <- solve(a, b)
print(res)

# Nachrechnen:
print(res[1] + 2 * res[2])
print(3 * res[1] - res[2])

# Versuchen eine nicht lösbare Gleichung zu lösen:
# a <- matrix(c(2, 3, 4, 6), nrow = 2, ncol = 2, byrow = TRUE)
# b <- c(7, 12)
# res <- solve(a, b)
# Aufruf von solve() schlägt fehl

# Versuchen eine Gleichung mit unendlich vielen Lösungen zu lösen
# a <- matrix(c(2, 3, 4, 6), nrow = 2, ncol = 2, byrow = TRUE)
# b <- c(7, 14)
# res <- solve(a, b)
# Aufruf von solve() schlägt fehl
