#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double x = 1.0;
	cout << scientific << setfill(' ');
	for(int i = 1; i <= 15; i++) {
		x = pow(10,-i);
		cout << "i = " << i << " x = " << x << " 1-sqrt(1.0-x*x) = " << 1.0-sqrt(1.0-x*x) << endl;
		cout << "i = " << i << " x = " << x << " (x*x)/(1.0+sqrt(1-x*x)) = " << (x*x)/(1.0+sqrt(1-x*x)) << endl;
	}
}