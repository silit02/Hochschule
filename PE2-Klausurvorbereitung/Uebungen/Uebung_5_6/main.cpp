#include <iostream>
#include "vektor2D.hpp"
using namespace std;

template <typename T>
T minimum(T a, T b){
	if(a<b)
		return a;
	else
		return b;
}

template <typename T>
void mySwap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

int main(){
	Vektor2D a(8);
	Vektor2D b(2,12);
	Vektor2D e(3,6);
	mySwap<Vektor2D>(b,e);
	cout << minimum<Vektor2D>(a,b) << endl;
	return 0;
}
	
	