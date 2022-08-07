#include "observer.hpp"
#include <sstream>
#include <iostream>
using namespace std;

void Subjekt::meldeAn(Observer *b) {
	_beobachter.push_back(b);
}

void Subjekt::meldeAb(Observer *b) {
	vector<Observer*>::iterator iter;
	for(iter = _beobachter.begin(); iter != _beobachter.end(); iter++) {
		if(*iter == b)
			break;
	}
	_beobachter.erase(iter);
}

void Subjekt::notify() {
	for(Observer* b: _beobachter) {
		b->print();
	}
}

Matrix::Matrix(int n, int m) {
	_colums = n;
	_rows = m;
	_mat = new int*[n];
	for(int i = 0; i<n; i++) {
		_mat[i] = new int[m];
	}
	
	for(int i = 0; i<_colums; i++) {
		for(int j = 0; j<_rows; j++){
			_mat[i][j] = 0;
		}
	}
}

string Matrix::gibWerte() const {
	ostringstream os;
	for(int i = 0; i<_colums; i++) {
		for(int j = 0; j<_rows; j++){
			os << _mat[i][j] << " ";
		}
		os << endl;
	}
	return os.str();
}

void Matrix::dataInput() {
	cout << "Eingabe Daten: " << endl;
	for(int i = 0; i<_colums; i++) {
		for(int j = 0; j<_rows; j++){
			cout << "matrix[" << i << "][" << j << "]: ";
			cin >> _mat[i][j];
		}
	}
	cout << endl;
}

Table::Table(Matrix* m) {
	subj = m;
}

void Table::print() {
	cout << subj->gibWerte() << endl;
}