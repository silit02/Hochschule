#include <iostream>
#include <cmath>
#include "gauss.hpp"
using namespace std;

int main() {
	//x-Werte speichern
	double x[] = {2048,4096,8192,16384,32768,65536};
	
	//y-Werte speichern
	double y[] = {2.8706e-1,5.5504e-1,1.2131,2.7139,5.8930,1.3380e+1};

	//Matrix G aufstellen
	double** G = newMat(6,3);
	for(int i = 0; i < 6; i++) {
		G[i][0] = x[i]*x[i];
		G[i][1] = x[i];
		G[i][2] = 1;
	}
	
	//transponierte Matrix G_ aufstellen
	double** G_ = newMat(3,6);
	for(int i = 0; i<6; i++) {
		for(int j = 0; j<3; j++) {
			G_[j][i] = G[i][j];
		}
	}
	
	//G_ * G berechnen
	double** A = mulMat(G_,3,6,G,6,3);
	
	//G_ * y berechnen
	double* r = mulMatVec(G_,3,6,y,6);
	
	//Gleichungssystem Aa = r lösen
	double* a = gaussSolve(A,r,3);  
	
	//Ausgabe Ergebnisse
	printVec(a,3);
}