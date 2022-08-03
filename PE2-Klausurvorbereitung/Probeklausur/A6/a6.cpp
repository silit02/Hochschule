#include <iostream>
#include "liste.hpp"
using namespace std;

template <typename T>
class MySet: public Liste<T> {
	friend ostream& operator<<(ostream &os, const MySet<T> &s);
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
        for (int i = 0; i < this->_last; i++) {
            if (this->find(s.getValueAt(i)) != -1) {
                inter.append(this->getValueAt(i));
            }
        }
		return inter;
    }

	MySet<T>& operator=(const MySet<T> &s) {

    }
};

template <typename T2>
ostream& operator<<(ostream &os, const MySet<T2> &s) {
	os << "{ ";
	for(int i = 0; i<s.size(); i++) {
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