#include <iostream>
#include <cmath>
using namespace std;

/**
 * Funktion zur Ausgabe einer quadratischen Matrix der Größe n x n
 * @param m Matrix (zweidimensionales Array), die ausgegeben werden soll
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
 * Funktion zur Ausgabe einer Matrix der Größe n x o
 * @param m Matrix, die ausgegeben werden soll
 * @param n Anzahl Zeilen der Matrix
 * @param o Anzahl Spalten der Matrix
 */
void printMat(double** m, int n, int o) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < o; j++) {
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
	//Speicher reservieren
    double **m = new double*[n];
    m[0] = new double[n*n];
    
    //Zeiger der Zeilen ausrichten
    for(int i = 0; i<n; i++) {
        m[i] = *m + (i*n);
    }
    return m;
}

/**
 * Funktion zur Erzeugung einer neuen uninitialisierten Matrix der Größe n x o
 * @param n Anzahl Zeilen der neuen Matrix
 * @param o Anzahl Spalten der neuen Matrix
 * @return Zeiger auf die neue Matrix
 */
double** newMat(int zeilen, int spalten) {
	//Speicher reservieren
    double **m = new double*[zeilen];
    m[0] = new double[zeilen*spalten];
    
    //Zeiger auf Zeilen ausrichten
    for(int i = 0; i<zeilen; i++) {
        m[i] = *m + (i * spalten);
    }
    return m;
}

/**
 * Funktion zur Speicherfreigabe einer Matrix
 * @param m Matrix, die Freigegeben werden soll
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
 * Funktion, die eine tiefe Kopie einer Matrix anlegt
 * @param m Matrix, die kopiert werden soll
 * @param zeilen Anzahl Zeilen der Matrix
 * @param spalten Anzahl Spalten der Matrix
 * @return Zeiger auf tiefe Kopie der Matrix
 */
double** copyMat(double** m, int zeilen, int spalten) {
    double **ret = newMat(zeilen, spalten);

    //Werte kopieren
    for(int i = 0; i<zeilen; i++) {
        for(int j = 0; j<spalten; j++) {
            ret[i][j] = m[i][j];
        }
    }
    return ret;
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
 * Funktion berechnet Multiplikation zweier Matrizen
 * @param m1 Matrix 1
 * @param zeilen1 Anzahl Zeilen von Matrix 1
 * @param spalten1 Anzahl Spalten von Matrix 1
 * @param m2 Matrix 2
 * @param zeilen2 Anzahl Zeilen von Matrix 2
 * @param spalten2 Anzahl Spalten von Matrix 2
 * @return Zeiger auf Ergebnis-Matrix. Falls Matrix-Multiplikation nicht möglich: nullptr
 */
double** mulMat(double** m1, int zeilen1, int spalten1, double** m2, int zeilen2, int spalten2) {
    if(zeilen1 != spalten2 || spalten1 != zeilen2) {
        //Matrix-Multiplikation kann nicht durchgeführt werden!
        cout << "Matrix-Multiplikation kann nicht durchgeführt werden!" << endl;
        return nullptr;
    }

    double** erg = newMat(zeilen1,spalten2);

    //Berechnung der Matrix-Multiplikation
    for(int i = 0; i<zeilen1; i++) {
        for(int j = 0; j<spalten2; j++) {
            double sum = 0;
            //Berechnung Summe 
            for(int k = 0; k<spalten1; k++) {
                    sum += (m1[i][k]*m2[k][j]);
            }
            erg[i][j] = sum;
        }
    }
    return erg;
}

/**
 * Funktion, die Matrix-Vektor-Multiplikation durchführt
 * @param m Matrix
 * @param zeilen Anzahl Zeilen der Matrix
 * @param spalten Anzahl Spalten der Matrix
 * @param v Vektor
 * @param n Größe n des Vektors
 * @return Zeiger auf Ergebnisvektor. Falls MAtrix-Vektor-Multiplikation nicht möglich: nullptr
 */
double* mulMatVec(double** m, int zeilen, int spalten, double* v, int n) {
    if(spalten != n) {
        //Matrix-Vektor-Multiplikation kann nicht durchgeführt werden!
        cout << "Matrix-Vektor-Multiplikation kann nicht durchgeführt werden!" << endl;
        return nullptr;
    }

    double* erg = newVec(n);

    //Berechnung der Multiplikation
    for(int i = 0; i<zeilen; i++) {

            double sum = 0;
            //Berechnung Summe
            for(int k = 0; k<spalten; k++) {
                    sum += (m[i][k]*v[k]);
            }
            erg[i] = sum;
        
    }
    return erg;
}
