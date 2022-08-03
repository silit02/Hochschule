#include <iostream>
#include "liste.hpp"
using namespace std;

template <typename T>
class MySet: public Liste<T> {
public:
	MySet(int size = 8): Liste<T>(size) {}

	MySet(const MySet<T> &s): Liste<T>(s) {}

	void append(T val) override {
        if(this->find(val) == -1){
            this->_values[this->_last] = val;
            this->_last++;
        }
    }

	MySet intersect(MySet<T> &s) {
        MySet<T> inter;
        for (int i = 0; i < this->size(); i++) {
            if (s.find(this->getValueAt(i)) != -1) {
                inter.append(this->getValueAt(i));
            }
        }
		return inter;
    }

	MySet<T>& operator=(const MySet<T> &s) {
		this->_last = s._last;
		this->_size = s._size;

		for(int i = 0; i<s.size(); i++){
			this->_values[i] = s._values[i];
		}
		return *this;
    }

	ostream& ausgabe(ostream &os) {
		os << "{ ";
		for(int i = 0; i<this->size(); i++) {
			os << this->getValueAt(i) << " ";
		}
		os << "}";
		return os;
	}
};

template <typename T>
ostream& operator<<(ostream &os, MySet<T> &s ) {
	return s.ausgabe(os);
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

	MySet<int> in;
	in = si.intersect(sd);

	cout << in << endl;
	return 0;
}