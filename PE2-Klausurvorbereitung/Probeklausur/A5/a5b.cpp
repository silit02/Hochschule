#include <iostream>
#include <string>
#include <sstream>
#include "stack.hpp"
using namespace std;

class ExtStack: public Stack {
	class StackIter{
	protected:
		int * _cursor;
	public:
		StackIter(int *cursor = nullptr);
		StackIter(const StackIter &iter);
		bool operator!=(StackIter iter);
		int& operator*() const;
		StackIter operator++(int);
	};
	
public:
	StackIter begin() const;
	StackIter end() const;
	string toString() const;
	ExtStack(int s = 8);
	~ExtStack();
};

ExtStack::StackIter::StackIter(int *cursor){
	_cursor = cursor;
}

ExtStack::StackIter::StackIter(const StackIter &iter){
	_cursor = iter._cursor;
}

bool ExtStack::StackIter::operator!=(StackIter iter) {
	return _cursor != iter._cursor;
}

int& ExtStack::StackIter::operator*() const{
	return *_cursor;
}

ExtStack::StackIter ExtStack::StackIter::operator++(int) {
	StackIter it = *this;
	_cursor++;
	return it;
}

ExtStack::StackIter ExtStack::begin() const {
	return StackIter(values);
}

ExtStack::StackIter ExtStack::end() const {
	return StackIter(values+pos);
}

string ExtStack::toString() const {
	ostringstream os;
	ExtStack::StackIter i;
	for(i=begin(); i!=end(); i++){
		os <<"| " << *i << " |";
	}
	return os.str();
}

ExtStack::ExtStack(int s): Stack(s) {}

ExtStack::~ExtStack() {
	delete[] values;
}

int main(){
	ExtStack s;
	for(int i = 0; i<10; i++){
		try{
			s.push(i*10);
		}catch(const char* e){
			puts(e);
		}
	}
	
	cout << "aktueller Stack: " << s.toString() << endl;
	
	while(!s.isEmpty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
		