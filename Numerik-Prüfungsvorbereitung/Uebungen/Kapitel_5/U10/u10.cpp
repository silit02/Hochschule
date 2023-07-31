#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a(double t) {
	return sin(t);
}

double v(double t) {
	return -cos(t)+2.0;
}

double s(double t) {
	return -sin(t) + 2.0*t;
}

double trapezregel(double(*f)(double), double unten, double oben, int stuetzstellen) {
	double integral = 0.0;
	double intervallbreite = (oben-unten)/(double)(stuetzstellen-1);
	for(int i = 0; i < stuetzstellen-1; i++) {
		double a = unten + i*intervallbreite;
		double b = a + intervallbreite;
		integral += (((b-a)/2.0)*f(a) + ((b-a)/2.0)*f(b));
	}
	return integral;
}

double simpsonregel(double(*f)(double), double unten, double oben, int stuetzstellen) {
	double integral = 0.0;
	double intervallbreite = (oben-unten)/(double)(stuetzstellen-1);
	for(int i = 0; i < stuetzstellen-1; i++) {
		double a = unten + i*intervallbreite;
		double b = a + intervallbreite;
		integral += ((intervallbreite/6.0)*(f(a)+4.0*f((a+b)/2.0)+f(b)));
	}
	return integral;
}

int main() {
	double ges[6];
	
	//Trapezregel Geschwindigkeiten
	cout << scientific << "Trapezregel Geschwindigkeiten" << endl;
	for(int t = 0; t<=5; t++) {
		double trapez = trapezregel(a,0.0,(double)t,10) + 1.0; //Anfangsgeschwindigkeit addieren
		double res = v(t);
		double error = fabs(trapez-res)/res;
		cout << t << " | " << trapez << " | " << error << " | " << res << endl;
	}
	
	//Simpson-Regel Geschwindigkeiten
	cout << scientific << "\nSimpson-Regel Geschwindigkeiten" << endl;
	for(int t = 0; t<=5; t++) {
		double simpson = simpsonregel(a,0.0,(double)t,10) + 1.0; //Anfangsgeschwindigkeit addieren
		double res = v(t);
		double error = fabs(simpson-res)/res;
		cout << t << " | " << simpson << " | " << error << " | " << res << endl;
		ges[t] = simpson;
	}
	
	//Trapezregel Strecke
	cout << "\nZurueckgelegte Strecke nach t = 5 Sekunden" << endl;
	double strecke = 0.0;
	for(int i = 1; i < 6; i++) {
		strecke += (0.5*ges[i] + 0.5*ges[i-1]);
	}
	double res = s(5.0);
	double error = fabs(strecke-res)/res;
	cout << 5 << " | " << strecke << " | " << error << " | " << res << endl;
	
}