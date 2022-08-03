#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int start, ende, schritt;
	cout << "Eingabe Startwert: ";
	cin >> start;
	cout << "Eingabe Endwert: ";
	cin >> ende;
	cout << "Eingabe Schrittweite: ";
	cin >> schritt;
	cout << endl;
	
	cout << setw(5) << "PS" << " |" << setw(5) << "KW" << endl;
	cout << "-------------" << endl;
	for(int i = start; i<=ende; i+=schritt){
		double kw = (double) i / 1.35962173;
		cout << setw(5) << i << " |" << setprecision(4) << setw(6) << kw << endl;
	}
	return 0;
}