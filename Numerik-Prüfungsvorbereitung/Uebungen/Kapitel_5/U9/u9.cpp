#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double s(double t) {
	return -sin(t) + 2.0*t;
}

double Ds(double t, double h) {
	return (s(t+h)-s(t))/h;
}

double Dzs(double t, double h) {
	return (s(t+h)-2.0*s(t)+s(t-h))/(h*h);
}

double extrapolation(double(*f)(double,double) ,double t, double h, int i, int k) {
	if(k == 0) {
		return f(t,h/(1 << i));
	} else {
		return (((double)(1 << k))*extrapolation(f,t,h,i+1,k-1)-extrapolation(f,t,h,i,k-1))/(((double)(1 << k))-1.0);
	}
}



int main() {
	//Ausgabe Ergebnisse vorbereiten
	cout << "Geschwindigkeit nach t Sekunden" << endl;
	cout << setfill(' ') << setw(3) << "t" << " | " << setw(17) << "v(t)" << " | " << setw(17) << "rel. Fehler" << " | " << setw(17) << "korrekt" << endl;
	cout << setfill('-') << setw(63) << "-" << endl;
	cout << setfill(' ');
	
	//Berechnung der Geschwindigkeit nach t = 1,2,3,4,5
	for(int t = 1; t<=5; t++) {
		cout << fixed << setw(3) << t << " | ";
		double abl = extrapolation(Ds,(double)t,0.1,0,3);
		
		//korrekte Lösung berechnen
		double a = -cos((double)t)+2.0;
		
		//relativen Fehler berechnen
		double err = fabs(abl-a)/a;
		
		//Ausgabe Ergebnisse
		cout << scientific << setprecision(10) << setw(17) << abl << " | " << setw(17) << err << " | " << setw(17) << a << endl;
	}
	
	
	
	//Ausgabe Ergebnisse vorbereiten
	cout << "\nBeschleunigung nach t Sekunden" << endl;
	cout << setfill(' ') << setw(3) << "t" << " | " << setw(17) << "v(t)" << " | " << setw(17) << "rel. Fehler" << " | " << setw(17) << "korrekt" << endl;
	cout << setfill('-') << setw(63) << "-" << endl;
	cout << setfill(' ');
	
	//Berechnung der Geschwindigkeit nach t = 1,2,3,4,5
	for(int t = 1; t<=5; t++) {
		cout << fixed << setw(3) << t << " | ";
		double abl = extrapolation(Dzs,(double)t,0.1,0,3);
		
		//korrekte Lösung berechnen
		double a = sin((double)t);
		
		//relativen Fehler berechnen
		double err = fabs(abl-a)/a;
		
		//Ausgabe Ergebnisse
		cout << scientific << setprecision(10) << setw(17) << abl << " | " << setw(17) << err << " | " << setw(17) << a << endl;
	}
}