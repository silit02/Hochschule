#include <iostream>
#include <cmath>
#include "gauss.hpp"
using namespace std;

int main() {
	int n = 33;
	
    //Vektor x-Werte und y-Werte aufstellen
    double *x = newVec(n);
    double *y = newVec(n);
    for(int i = 0; i<n; i++) {
        x[i] = (double)i;
        y[i] = cos(6*i*2*M_PI/33.0) + 0.5*sin(4*i*2*M_PI/33.0 + (rand()%5+1.0)/100.0);
    }
	
	//inverse Matrix aufstellen
	double** mat = newMat(n);
	for(int i = 0; i<n; i++) {
        mat[0][i] = 1.0/(double)n;
        for(int j = 1; j<=n/2; j++) {
            mat[j][i] = 2.0/((double)n)*cos(j*2.0*M_PI*x[i]/33.0);
            mat[j+n/2][i] = 2.0/((double)n)*sin(j*2.0*M_PI*x[i]/33.0);
        }
    }
	
	//Matrix-Vektor-Multiplikation
	double* a = mulMatVec(mat,n,n,y,n);
	
	//Ausgabe Ergebnis
	printVec(a,n);
	
}