#include <iostream>
#include <cmath>
//#define test
using namespace std;

/**
 * Funktion zur Ausgabe einer quadratischen Matrix der Größe n x n
 * @param m Matrix (zweidimensionales Array), das ausgegeben werden soll
 * @param n Größe der Matrix n x n
 */
void printMat(double** m, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Funktion zur Erzeugung einer neuen uninitialisierten Matrix der Größe n x n
 * @param n Größe der Matrix n x n
 * @return Zeiger auf die neue Matrix
 */
double** newMat(int n) {
    double **m = new double*[n];
	m[0] = new double[n*n];
    for(int i = 1; i<n; i++) {
        m[i] = *m+(i*n);
    }
    return m;
}

/**
 * Funktion zur Speicherfreigabe einer n x n Matrix
 * @param m Matrix, die Freigegeben werden soll
 * @param n Größe der Matrix n x n
 */
void delMat(double** m) {
	delete m[0];
    delete[] m;
}

/**
 * Funktion zur Ausgabe eines Vektors der Größe n
 * @param v Zeiger auf den Vektor
 * @param n Größe n des Vektors
 */
void printVec(double* v, int n) {
    for(int i = 0; i<n; i++) {
        cout << v[i] << "\n";
    }
    cout << flush;
}

/**
 * Funktion zur Erzeugung eines uninitialisierten Vektors der Größe n
 * @param n Größe n des Vektors
 * @return Zeiger auf den neuen Vektor
 */
double* newVec(int n) {
    return new double[n];
}

/**
 * Funktion zur Speicherfreigabe eines Vektors
 * @param v Vektor, der freigegeben werden soll
 */
void delVec(double* v) {
    delete[] v;
}

/**
 * Funktion erzeugt eine neue quadratische Matrix der Größe n x n und initialisiert diese mit ganzzahligen Zufallswerten zwischen 0 und 4
 * @param n Größe n der Matrix
 * @return Zeiger auf die neue zufällige Matrix
 */
double** randomMat(int n) {
    double **m = newMat(n);

    // Seed für die Zufallszahlengenerierung festlegen
    srand(clock());
    
    //Zufallszahlen zwischen 0 und 4 einfügen
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            // Zufallszahl zwischen 0 und 4 generieren
            m[i][j] = (double)(rand() % 5);
        }
    }
    return m;
}

/**
 * Funktion erzeugt einen neuen Vektor der Größe n und initialisiert diesen mit ganzzahligen Zufallswerten zwischen 0 und 4
 * @param n Größe n des Vektors
 * @return Zeiger auf den neuen zufälligen Vektor
 */
double* randomVec(int n) {
    double *v = newVec(n);

    // Seed für die Zufallszahlengenerierung festlegen
    srand(clock());
    
    //Zufallszahlen zwischen 0 und 4 einfügen
    for(int i = 0; i<n; i++) {
        // Zufallszahl zwischen 0 und 4 generieren
        v[i] = (double)(rand() % 5);
    }
    return v;
}

/**
 * Funktion führt Gauss-Elimination durch
 * @param a Matrix, die in Zeilenstufenform umgeformt wird
 * @param b Vektor, der zur Matrix gehört und verändert wird
 * @param n Größe der n x n Matrix bzw. n des Vektors
 * @return Bool, ob der die Matrix eine Lösung hat (false, falls Matrix singulär)
 */
bool gauss(double** a, double* b, int n) {
    double** l = newMat(n); //Speichert die Faktoren der Gauss-Elimination

    //Für jede Zeile k ausser der letzten
    for(int k = 0; k<n-1; k++) {

        //Spaltenpivotsuche
        int maxzeile = k;

        //Maximum bestimmen
        for(int m = k+1; m<n; m++) {
            if(fabs(a[m][k]) > fabs(a[maxzeile][k])) {
                maxzeile = m;
            }
        }

        //Falls Null auf Diagonalen: Matrix ist Singulär und hat keine Lösung
        if(fabs(a[maxzeile][k]) == 0) {
            return false;
        }

        //Vertausche Zeilen k und maxzeile falls k != maxzeile
        if(maxzeile != k) {
            //Zeilen vertauschen
            double *tmp = a[k];
            a[k] = a[maxzeile];
            a[maxzeile] = tmp;
            
            //Vektorelemente vertauschen
            double tmp2 = b[k];
            b[k] = b[maxzeile];
            b[maxzeile] = tmp2;
        }

        //unten liegende Zeilen i durchgehen und Faktoren berechnen
        for(int i = k+1; i<n; i++) {
            l[i][k] = a[i][k]/a[k][k];
        }

        //unten liegende Zeilen i durchgehen und neue Werte berechnen
        for(int i = k+1; i<n; i++) {
            //rechts liegende Spalten j von i durchgehen
            for(int j = k; j<n; j++) {
                a[i][j] = a[i][j] - l[i][k]*a[k][j];
            }
            //Rechte Seite ändern
            b[i] = b[i] - l[i][k]*b[k];
        }
    }
    return true;
}

/**
 * Funktion zur Lösung eines Gleichungssystems einer Matrix in Zeilenstufenform
 * @param a Matrix in Zeilenstufenform
 * @param b Vektor zur Matrix in Zeilenstufenform
 * @param n Größe der Matrix n x n und Größe des Vektors n
 * @return Zeiger auf den Ergebnisvektor des Gleichungssystems
 */
double* solve(double **a, double* b, int n) {
    double *result = newVec(n);

    //Matrix liegt in Zeilenstufenform vor

    //erstes Ergebnis berechnen
    result[n-1] = b[n-1]/a[n-1][n-1];

    //andere Ergebnisse berechnen
    double absWert;
    for(int i = n-2; i>=0; i--) {
        //absWert berechnen
        absWert = 0;
        for(int j = i+1; j<n; j++) {
            absWert += a[i][j]*result[j];
        }

        //Unbekannte Ausrechnen
        result[i] = (b[i]-absWert)/a[i][i];
    }
    return result;
}

/**
 * Funktion führt Gauss-Elimination durch und berechnet den Ergebnisvektor
 * @param mat quadratische Matrix der Größe n x n
 * @param vec Vektor der Größe n
 * @param n Größe der Matrix/des Vektors
 * @return Zeiger auf den Ergebnisvektor. Falls es keine (eindeutige) Lösung gibt: nullptr
 */
double* gaussSolve(double** mat, double* vec, int n) {
    if(!gauss(mat,vec,n)) {
        return nullptr;
    }
    return solve(mat, vec, n);
}

/**
 * Main-Funktion zum Test des Programms
 * @return Return-Code des Programms
 */
int main() {
    int n = 4;

#ifdef test
    double **mat = newMat(n);
    double *vec = newVec(n);

    //Initialisierung der Matrix
    mat[0][0] = 1;
    mat[0][1] = 3;
    mat[0][2] = 2;
    mat[0][3] = 9;

    mat[1][0] = 2;
    mat[1][1] = 6;
    mat[1][2] = 4;
    mat[1][3] = 18;

    mat[2][0] = 2;
    mat[2][1] = 6;
    mat[2][2] = 4;
    mat[2][3] = 3;

    mat[3][0] = 4;
    mat[3][1] = 3;
    mat[3][2] = 2;
    mat[3][3] = 1;

    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
#else
    double **mat = randomMat(n);
    double *vec = randomVec(n);
#endif
    cout << "Ursprungsmatrix\n";
    printMat(mat, n);
    cout << "\nUrsprungsvektor\n";
    printVec(vec,n);

    if(!gauss(mat,vec,n)) {
        cout << "\nMatrix ist singulär!" << endl;
        return -1;
    }

    cout << "\nMatrix in Zeilenstufenform\n";
    printMat(mat,n);
    cout << "\nVektor zur Matrix in Zeilenstufenform\n";
    printVec(vec,n);

    //Ergebnis ausgeben
    cout << "\nErgebnisvektor\n";
    printVec(solve(mat,vec,n),n);

    delMat(mat);
    delVec(vec);
    return 0;
}