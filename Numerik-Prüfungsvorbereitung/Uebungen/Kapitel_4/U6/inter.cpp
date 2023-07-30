#include <iostream>
#include <cmath>
#include "gauss.hpp"
using namespace std;

#define N 9

int main() {
	//Stützstellen abspeichern
	double x[] = {-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0};
	
	//Stützwerte berechnen
	double y[N];
	for(int i = 0; i<N; i++) {
		y[i] = exp(-x[i] * x[i]);
	}
	
	//Vandermonde-Matrix aufstellen
	double** V = newMat(N);
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<N; j++) {
			V[i][j] = pow(x[i],j);
		}
	}
	
	//Gleichungssystem lösen
	double* a = gaussSolve(V,y,N);
	
	//Ergebnisse ausgeben
	printVec(a,N);
}