#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f1(double x1, double x2) {
	return (x1*x1*x1) + (x2*x2*x2) - (3.0*x1) - (27.0*x2) + 24.0;
}

double f2(double x1, double x2) {
	return -(100.0/((x1-1.0)*(x1-1.0) + (x2-1.0)*(x2-1.0) + 1.0)) - (200/((x1+1)*(x1+1) + (x2+1.0)*(x2+1.0) + 1.0));
}

double* grad_f1(double x1, double x2) {
	double* grad = new double[2];
	grad[0] = 3.0*(x1*x1) - 3.0;
	grad[1] = 3.0*(x2*x2) - 27.0;
	return grad;
}

double* grad_f2(double x1, double x2) {
	double* grad = new double[2];
	double n1 = ((x1-1.0)*(x1-1.0) + (x2-1.0)*(x2-1.0) + 1.0);
	double n2 = ((x1+1)*(x1+1) + (x2+1.0)*(x2+1.0) + 1.0);
	grad[0] = 100/(n1*n1)*2.0*(x1-1.0) + 200.0/(n2*n2)*2.0*(x1+1.0);
	grad[1] = 100/(n1*n1)*2.0*(x2-1.0) + 200.0/(n2*n2)*2.0*(x2+1.0);
	return grad;
}

int main() {
	double n = 0.08;
	double precision = 1e-11;
	int maxIteration = 1000;
	int count = 0;
	double grad_betrag = 1.0;
	double* result = new double[2];
	result[0] = 0.5;
	result[1] = -1.0;
	
	//Gradientenverfahren f1
	while(count < maxIteration && grad_betrag > precision) {
		double* grad = grad_f1(result[0], result[1]);
		for(int i = 0; i<2; i++) {
			result[i] = result[i] - n*grad[i];
		}
		grad_betrag = sqrt(grad[0]*grad[0] + grad[1]*grad[1]);
		delete[] grad;
		count++;
	}
	
	//Ausgabe Ergebnisse f1
	cout << scientific << setprecision(15) << "Maximum bei x1 = " << result[0] << " und x2 = " << result[1] << endl;
	cout << "f(" << result[0] << ", " << result[1] << ") = " << f1(result[0],result[1]) << endl;
	cout << "Iterationen:" << count << endl; 
	
	//Gradientenverfahren f2
	n = 0.001;
	count = 0;
	grad_betrag = 1.0;
	result[0] = -1.0;
	result[1] = -1.0;
	
	while(count < maxIteration && grad_betrag > precision) {
		double* grad = grad_f2(result[0], result[1]);
		for(int i = 0; i<2; i++) {
			result[i] = result[i] - n*grad[i];
		}
		grad_betrag = sqrt(grad[0]*grad[0] + grad[1]*grad[1]);
		delete[] grad;
		count++;
	}
	
	//Ausgabe Ergebnisse f2
	cout << scientific << setprecision(15) << "\nMaximum bei x1 = " << result[0] << " und x2 = " << result[1] << endl;
	cout << "f(" << result[0] << ", " << result[1] << ") = " << f2(result[0],result[1]) << endl;
	cout << "Iterationen:" << count << endl; 
	
	delete[] result;
}