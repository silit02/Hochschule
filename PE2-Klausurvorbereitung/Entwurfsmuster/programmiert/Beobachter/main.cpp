#include "observer.hpp"
#include <iostream>
using namespace std;

int main() {
	Matrix m(2,2);
	
	m.meldeAn(new Table(&m));
	m.notify();
	m.dataInput();
	m.notify();
	return 0;
}