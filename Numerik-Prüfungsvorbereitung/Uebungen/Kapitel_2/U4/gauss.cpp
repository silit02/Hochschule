/**
@file Prgramm, dass die Gauss-Elimination implementiert
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
Funktion zur Erzeugung einer initialisierten quadratischen Matrix
@param n Anzahl der Spaten/Zeilen der Matrix
@param init Initialer Wert der Matrix (Default a = 1)
@return Zeiger auf die erzeugte Matrix
*/
double** newMat(int n, double init = 1) {
	//Speicher reservieren
	double** m = new double*[n];
	m[0] = new double[n*n];
	for(int i = 1; i<n; i++) {
		m[i] = *m+(i*n);
	}
	
	//Matrix initialisieren
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			m[i][j] = init;
		}
	}
	
	return m;
}

/**
Funktion zur Speicherfreigabe einer Matrix
@param m Zeiger auf die freizugebende Matrix
*/
void delMat(double** m) {
	delete[] m[0];
	delete[] m;
}

/**
Funktion zur Erzeugung eines initialisierten Vektors der Länge n
@param n Anzahl der Elemente des Vektors
@param init Initialer Wert der Vektorelemente
@return Zeiger auf den erzeugten Vektor
*/
double* newVec(int n, double init = 1) {
	//Speicher reservieren
	double* v = new double[n];
	
	//Vektor initialisieren
	for(int i = 0; i<n; i++) {
		v[i] = init;
	}
	
	return v;
}

/**
Funktion zur Speicherfreigabe eines Vektors
@param v Zeiger auf den freizugebenden Vektor
*/
void delVec(double* v) {
	delete[] v;
}

/**
Funktion, die eine Gauss-Elimination mit Spaltenpivotsuche durchführt. Übergebene Matrix und Vektor werden modifiziert.
@param m Zeiger auf die Matrix, die in Zeilenstufenform umgeformt werden soll
@param v Zeiger auf den Vektor, der die rechte Seite des Gleichungssystems bildet
@param n Größe der Matrix/des Vektors in einer Dimension
@return boolean, ob das Gleichungssystem eine Lösung hat
*/
bool gauss_elimination(double** m, double*v, int n) {
	double** l = newMat(n);
	for(int i = 0; i < n-1; i++) {
		
		//Spaltenpivotsuche für aktuelle Spaltenpivotsuche
		
		//betragsmäßig größtes Element in aktueller Spalte suchen
		int maxzeile = i;
		for(int k = i+1; k<n; k++) {
			if(fabs(m[k][i]) > fabs(m[maxzeile][i])) {
				maxzeile = k;
			}
		}
		
		//Falls größtes Element 0: Determinante der Matrix ist 0, also hat Gleichungssystem keine Lösung
		if(fabs(m[maxzeile][i]) == 0) {
			return false;
		}
		
		//Zeile des betragsmäßig größten Elements mit der aktuellen Zeile des Diagonalelements vertauschen
		if(maxzeile != i) {
			//Zeilen Matrix tauschen
			double* tmp = m[maxzeile];
			m[maxzeile] = m[i];
			m[i] = tmp;
			
			//Elemente Vektor tauschen
			double tmp2 = v[maxzeile];
			v[maxzeile] = v[i];
			v[i] = tmp2;
		}
		
		//Gauss-Elimination durchführen
		
		
		//Zeilen unter dem Diagonalelement der aktuellen Spalte durchgehen und Faktoren berechnen
		for(int j = i+1; j < n; j++) {
			l[j][i] = m[j][i]/m[i][i];
		}
		
		//Zeilen unter dem Diagonalelement der aktuellen Spalte durchgehen und Elemente zu 0 machen
		for(int j = i+1; j < n; j++) {
			//Elemente der Zeile durchgehen
			for(int k = i; k < n; k++) {
				m[j][k] = m[j][k] - (l[j][i] * m[i][k]);
			}
			
			//Vektorelemente bearbeiten
			v[j] = v[j] - (l[j][i] * v[i]);
		}
		
	}
	delMat(l);
	return true;
}

/**
Funktion, die ein GLeichungssystem löst und den Ergebnisvektor berechnet.
@param m Matrix in Zeilenstufenform
@param v Vektor der rechten Seite des Gleichungssystems
@param n Größe der Matrix/des Vektors in einer Dimension
@return Zeiger auf den Ergebnisvektor
*/
double* solve(double** m, double* v, int n) {
	double* x = newVec(n);
	double sum;
	
	//x[n] berechnen
	x[n-1] = v[n-1]/m[n-1][n-1];
	
	for(int k = n-2; k >= 0; k--) {
		
		//Summe der bekannten Elemente berechnen
		sum = 0.0;
		for(int i = k+1; i < n; i++) {
			sum += (m[k][i] * x[i]);
		}
		x[k] = (v[k] - sum)/m[k][k];
	}
	
	return x;
}

/**
Funktion, die das Gleichungssystem Ax = b mittels Gauss-Elimination löst und den Ergebnisvektor berechnet.Übergebene Matrix und Vektor werden modifiziert.
@param m Zeiger auf die Matrix des Gleichungssystems
@param v Zeiger auf den Vektor des Gleichungssystems
@param n Größe der Matrix/des Vektors in einer Dimension
@return Zeiger auf den Ergebnisvektor, nullptr falls LGS keine Lösung hat
*/
double* gauss(double**m, double* v, int n) {
	if(!gauss_elimination(m,v,n)) {
		return nullptr;
	}
	return solve(m,v,n);
}

int main() {
	double** m = newMat(3);
	double* v = newVec(3);
	
	//Testdaten in Matrix und Vektor schreiben
	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = -1;
	
	m[1][0] = 1;
	m[1][1] = 1;
	m[1][2] = 2;
	
	m[2][0] = 2; 
	m[2][1] = 3;
	m[2][2] = -3;
	
	v[0] = 2;
	v[1] = 9;
	v[2] = -1;
	
	//Gauss-Elimination durchführen
	double* x = gauss(m,v,3);
	
	//Ausgabe Ergebnisvektor
	for(int i = 0; i < 3; i++) {
		cout << x[i] << endl;
	}
	
	delMat(m);
	delVec(v);
}
	