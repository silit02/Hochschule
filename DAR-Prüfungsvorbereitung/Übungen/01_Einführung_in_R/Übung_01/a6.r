#
# Script zum Üben Debuggen (Fehler behoben)
#

s <- "blablabla"
for (i in 1:nchar(s)) {
  substr(s, i, i) <- "x"
}
print(s)

s <- "blablabla"

s <- gsub(".", "x", s)

cat(sprintf("Mittels gsub: %s\n", s))

s <- "blablabla"

s <- paste(rep("x", nchar(s)), collapse = "")

cat(sprintf("Mittels paste und rep: %s\n", s))
