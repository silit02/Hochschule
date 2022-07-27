/** @file editDistance.cpp
******************************************************************************
* Uebung 13, ALD
* Gerüst zur Berechnung der Levenshtein-Distanz (dynamische Programmierung)
* Übergabeparameter ist eine Wörterbuch
* Ausgabe alle Wörter mit einer Editierdistanz kleiner gleich 4
*****************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>   // for std::min
#include <cstring>     // for strerror()
#include <cerrno>      // for errno
using namespace std;

/**
****************************************************************************
* Tabelle für die Einträge zur Berechnung der
* Levenshtein-Distanz mittels dynamischer Programmierung
****************************************************************************/
size_t dist[64][64];

/**
****************************************************************************
* Funktion  void levenshtein_a(string s, string t)
* Zweck: Gíbt die berechnete Tabelle der Levenshteindistanz aus
*
* @param     s,t:             die zu vergleichenden Strings
* @return    dist[n-1][m-1]:  die Levenshtein-Distanz
****************************************************************************/

void levenshtein_a(string s, string t) {
    cout << "  ";
    for(int i = 0; i<=t.size();i++){
        if(i == 0)
            cout << "# ";
        else
            cout << t[i-1] << " ";
    }
    cout << endl;

    //Ausgabe:
    for(int i = 0; i<=s.size(); i++){
        if(i == 0)
            cout << "#";
        else
            cout << s[i-1];
        for(int j = 0; j<=t.size(); j++){
            cout << " " << dist[i][j];
        }
        cout << endl;
    }

}

/**
****************************************************************************
* Funktion  size_t levenshtein(string s, string t)
* Zweck: Berechnet die Levenshtein-Distanz zwischen den übergebenen Strings
*
* @param     s,t:             die zu vergleichenden Strings
* @return    dist[n-1][m-1]:  die Levenshtein-Distanz
****************************************************************************/

size_t levenshtein(string s, string t) {
    size_t a,b,c;

    //0. Zeile und Spalte füllen
    for(int i = 0; i<=s.size(); i++){
        dist[i][0] = i;
    }

    for(int j = 0; j<=t.size(); j++){
        dist[0][j] = j;
    }

    //Tabelle ausfüllen
    for(int i = 1; i<=s.size(); i++){
        for(int j = 1; j<=t.size(); j++){
            if(s[i-1] == t[j-1])
                a = dist[i-1][j-1] + 0;
            else
                a = dist[i-1][j-1] + 1;
            b = dist[i][j-1] + 1;
            c = dist[i-1][j] + 1;

            dist[i][j] = min(min(a,b),c);
        }
    }

    //Tabelle ausgeben 
    cout << endl;
    levenshtein_a(s,t);
    cout << endl;
    
    return dist[s.size()][t.size()];
}

/********************************************************************/

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cerr << "usage: " << argv[0] << " Wort1 Wort2" << endl;
        return 1;
    }

    string wort1(argv[1]);
    string wort2(argv[2]);

	size_t distance = levenshtein(wort1, wort2);
	
	cout << "Levenshtein-Distanz von \"" << wort1 << "\" und \"" << wort2 << "\": " << distance << endl;
	return 0;
}
