#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	float x = 1;
	for(int i = 1; i<=20; i++) {
		float h = powf(10,-i);
		float dx = (sin(x+h)-sin(x))/h;
		float err = fabs(dx-cos(x))/cos(x);
		cout << scientific << h << " | " << dx << " | " << err << endl;
	}
	cout << "korrekte Lösung: " << cos(x) << endl;
}