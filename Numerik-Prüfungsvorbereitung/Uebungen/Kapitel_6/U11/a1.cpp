#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
	return x*x - 2.0;
}

double f_(double x) {
	return 2.0*x;
}

double F(double x) {
	return 2.0/(x*x)-1.0;
}

double bisektion(double(*f)(double), double a, double b, double genauigkeit) {
	if(b-a < genauigkeit) {
		return a;
	} else {
		double m = (a+b)/2.0;
		if(f(a)*f(m) < 0) {
			return bisektion(f, a, m, genauigkeit);
		} else {
			return bisektion(f, m, b, genauigkeit);
		}
	}
}

int main() {
	//Ausgabe richtiges Ergebnis
	double res = sqrt(2);
	cout << scientific << setprecision(20) << "sqrt(2) = " << res << endl;
	
	//Newton-Verfahren
	double x = 1.4;
	double last_x;
	do {
		last_x = x;
		x = x - (f(x)/f_(x));
	}while(fabs(last_x - x) > 1e-11);
	
	//Berechnung relativer fehler
	double error = fabs(res - x)/res;
	
	//Ausgabe Ergebnis
	cout << "sqrt(2) = " << x << " (Newton-Verfahren) | " << error << endl;
	
	//Bisektionsverfahren
	x = bisektion(f, 1.4,1.5,1e-11);
	
	//Berechnung relativer Fehler
	error = fabs(res - x)/res;
	
	//Ausgabe Ergebnis
	cout << "sqrt(2) = " << x << " (Bisektionsverfahren) | " << error << endl;
	
	//Fixpunktiteration
	x = 1.4;
	do {
		last_x = x;
		x = x + F(x);
	}while(fabs(last_x - x) > 1e-11);
	
	//Berechnung relativer Fehler
	error = fabs(res - x)/res;
	
	//Ausgabe Ergebnis
	cout << "sqrt(2) = " << x << " (Fixpunktiteration) | " << error << endl;
}