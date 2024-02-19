# Von welchem Datentype ist der Vektor x nach jeder der Anweisungen?
x <- seq(1, 10) # integer
x <- x > 5 # logical
x <- c(x, "1") # character
# Wenn jetzt nach Numeric konvertiert: NAs produziert, wenn String keine Zahl
