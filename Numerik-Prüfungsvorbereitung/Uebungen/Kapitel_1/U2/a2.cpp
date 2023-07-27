#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	//Richtiges Ergebnis berechnen
	cout << "(math.h): e^-20 = " << scientific << setprecision(10) << exp(-20.0) << endl;
	
	//Berechnung float e^-20
	float xf = -20.0;
	float resultf = 1.0;
	float last_resultf = 1.0;
	float termf = 1.0;
	float last_termf = 1.0;
	int i_f = 1;
	do {
		last_resultf = resultf;
		last_termf = termf;
		termf = last_termf * ((float)xf/(float)i_f);
		resultf += termf;
		i_f++;
	} while(last_resultf != resultf);
	cout << "Berechnung float e^-20: " << resultf << endl;
	
	//Berechnung double e^-20
	double x = -20.0;
	double result = 1.0;
	double last_result = 1.0;
	double term = 1.0;
	double last_term = 1.0;
	int i = 1;
	do {
		last_result = result;
		last_term = term;
		term = last_term * ((double)x/(double)i);
		result += term;
		i++;
	} while(last_result != result);
	cout << "Berechnung double e^-20: " << scientific << result << endl;
	
	//Berechnung float 1/e^20
	xf = 20.0;
	resultf = 1.0;
	last_resultf = 1.0;
	termf = 1.0;
	last_termf = 1.0;
	i_f = 1;
	do {
		last_resultf = resultf;
		last_termf = termf;
		termf = last_termf * ((float)xf/(float)i_f);
		resultf += termf;
		i_f++;
	} while(last_resultf != resultf);
	cout << "Berechnung float 1/e^20: " << scientific << (float)1/resultf << endl;
	
	//Berechnung double 1/e^20
	x = 20.0;
	result = 1.0;
	last_result = 1.0;
	term = 1.0;
	last_term = 1.0;
	i = 1;
	do {
		last_result = result;
		last_term = term;
		term = last_term * ((double)x/(double)i);
		result += term;
		i++;
	} while(last_result != result);
	cout << "Berechnung double 1/e^20: " << scientific << 1.0/result << endl;
}