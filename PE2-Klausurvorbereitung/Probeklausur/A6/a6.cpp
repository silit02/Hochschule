#include <iostream>
#include "liste.hpp"
using namespace std;

template <typename T>
class MySet: public Liste<T> {
	friend ostream& operator<<(ostream &os, const MySet &s);
public:
	MySet(int size = 8);
	MySet(const MySet<T> &s);
	void append(T val);
	MySet intersect(const MySet<T> &s);
	void operator=(const MySet<T> &s);
};

template <typename T>
MySet<T>::MySet(int size): Liste<T>(size) {}

template <typename T>
MySet<T>::MySet(const MySet<T> &s): Liste<T>(s) {}

template <typename T>
void MySet<T>::append(T val) {
	if(this->find(val) == -1){
		this->_values[_last] = val;
		_last++;
	}
}

template <typename T>
MySet<T> MySet<T>::intersect(const MySet<T> &s) {
	MySet<T> inter;
	for(int i = 0; i<_last; i++){
		if(s.find(getValueAt(i)) != -1){
			inter.append(getValueAt(i));
		}
	}
	return inter;
};

template <typename T>
ostream& operator<<(ostream &os, const MySet<T> &s) {
	os << "{ ";
	for(int i = 0; i<size<T>(); i++) {
		os << s.getValueAt(i) << " ";
	}
	os << " }";
	return os;
}

int main() {
	MySet<int> si;
	MySet<int> sd;
	
	si.append(2);
	si.append(5);
	si.append(6);
	si.append(5);
	
	cout << si << endl;
	
	sd.append(2);
	
	cout << sd << endl;
	
	cout << si.intersect(sd) << endl;
	return 0;
}