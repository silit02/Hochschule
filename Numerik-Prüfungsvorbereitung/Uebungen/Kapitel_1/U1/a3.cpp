#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
* Funktion berechnet die in der Aufgabenstellung gegebenen Formel mit dem Datentyp float
*/
float binom_f(float a, float b) {
	return ((a+b)*(a+b)-(a*a)-((float)2*a*b))/(b*b);
}

/**
* Funktion berechnet die in der Aufgabenstellung gegebenen Formel mit dem Datentyp double
*/
float binom_d(double a, double b) {
	return ((a+b)*(a+b)-(a*a)-(2.0*a*b))/(b*b);
}

int main() {
	//Berechnung in float
	cout << "Ergebnisse float: " << scientific << endl;
	for(int i = 0; i <= 10; i++) {
		cout << "i = " << i << ": " << binom_f(1000, powf(10,-i)) << endl;
	}
	
	//Berechnung in double
	cout << "\nErgebnisse double:" << endl;
	for(int i = 0; i <= 10; i++) {
		cout << "i = " << i << ": " << binom_d(1000, pow(10,-i)) << endl;
	}
}
	