#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double a) {
	return (M_PI/(2.0*cos(a))+a-M_PI-tan(a));
}

double f_(double a) {
	return ((M_PI*tan(a))/(2.0*cos(a))-(tan(a)*tan(a)));
}

int main() {
	//Nullstelle der Gleichung mittels Newton-Verfahren bestimmen
	double x = 5.0*M_PI/12.0;
	double last_x;
	do {
		last_x = x;
		x = x - (f(x)/f_(x));
	}while(fabs(x-last_x) > 1e-15);
	
	//Berechnung des Verhältnisses r/R
	double res = sqrt(2.0*(1-cos(x)));
	cout << scientific << setprecision(15) << "r/R = " << res << endl;
}