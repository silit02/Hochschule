#ifndef _OBSERVER_HPP
#define _OBSERVER_HPP

#include <vector>
#include <string>

class Observer{
public:
	virtual void print() = 0;
};

class Subjekt{
protected:
	std::vector<Observer*> _beobachter;
public:
	void meldeAn(Observer *b);
	void meldeAb(Observer *b);
	void notify();
};

class Matrix: public Subjekt {
protected:
	int _colums, _rows;
	int** _mat;
public:
	Matrix(int n, int m);
	std::string gibWerte() const;
	void dataInput();
};
	
class Table: public Observer {
	Matrix* subj;
public:
	Table(Matrix* m);
	void print() override;
};
	
#endif