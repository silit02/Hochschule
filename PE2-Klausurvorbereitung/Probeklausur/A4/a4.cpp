#include <iostream>
using namespace std;

template <typename T, int N>
class MyVector {
	T data[N]; //default-Konstruktor
	
public:
	MyVector() {
		for(int i = 0; i<N; ++i)
			data[i] = T(0); //Konstruktor benötigt
	}
	
	T& operator[] (int index) {
		if((index < 0) or (index >= N))
			throw "out of range";
		return data[index];
	}
	
	bool lessThan (MyVector& arg) {
		for(int i = 0; i<N; ++i) {
			if(data[i] < arg[i]) //operator< benötigt
				return true;
		}
		return false;
	}
};

template <typename T, int N>
ostream& operator<<(ostream& os, MyVector<T, N>&arg) {
	os << "{\n";
	for(int i = 0; i<N; ++i)
		os << "\t" << arg[i] << endl; //operator<< benötigt
	os << "}\n";
	return os;
}

struct Bruch {
	int zaehler, nenner;
	
	Bruch(int z, int n) {
		zaehler = z;
		nenner = n;
	}
	
	Bruch(int z = 0) {
		zaehler = z;
		nenner = 1;
	}
	
	bool operator<(Bruch &b) {
		if(nenner > b.nenner || (nenner == b.nenner && zaehler < b.zaehler))
			return true;
		return false;
	}
	
	//friend ostream& operator<<(ostream& os, Bruch &b);
	
	
};

ostream& operator<<(ostream& os, Bruch &b){
	os << "(" << b.zaehler << "/" << b.nenner << ")";
	return os;
}

int main(){
	MyVector<Bruch, 5> v;
	MyVector<Bruch, 5> c;
	
	for(int i = 0; i<5; i++){
		v[i] = {i+1, 2};
		c[i] = {i-1, 2};
	}
	
	cout << "v: " << v << endl;
	cout << "c: " << c << endl;
	
	if(c.lessThan(v))
		cout << "c<v" << endl;
}