#ifndef _TSTACK_HPP
#define _TSTACK_HPP

#include <string>
#include <sstream>

template <typename T>
class Stack{
	template <typename T2>
	friend std::ostream& operator<<(std::ostream& os, const Stack<T2> &s);
	
	class stackIter{
	private:
		T* _cursor;
	public:
		stackIter(T* cursor = nullptr) {
			_cursor = cursor;
		}
		
		bool operator!=(const stackIter &si) {
			return _cursor != si._cursor;
		}
		
		stackIter operator++(int) {
			stackIter tmp = *this;
			_cursor++;
			return tmp;
		}
		
		T* operator*() {
			return _cursor;
		}
		
	};
	
protected:
	int _size;
	int _next;
	T* _values;
	
	bool isFull() const{
		return _next >= _size;
	}
	
	void increase() {
		T* tmp = new T[_size*2];
		for(int i = 0; i<_next ;i++){
			tmp[i] = _values[i];
		}
		
		delete[] _values;
		_values = tmp;
	}
	
	void decrease() {
		T* tmp = new T[_size/2];
		for(int i = 0; i<_next ;i++){
			tmp[i] = _values[i];
		}
		
		delete[] _values;
		_values = tmp;
	}
	
public:
	Stack(int size = 8) {
		_size = size;
		_next = 0;
		_values = new T[size]; //Default-Konstruktor für T benötigt
	}
	
	Stack(const Stack &s) {
		_size = s._size;
		_next = s._next;
		for(int i = 0; i<s._next; i++) {
			_values[i] = s._values[i];
		}
	}
	
	~Stack() {
		delete[] _values;
	}
	
	bool isEmpty() const{
		return _next == 0;
	}
	
	void push(T val) {
		if(isFull())
			increase();
		
		_values[_next++] = val;
	}
	
	void pop() {
		if(isEmpty())
			throw std::string("StackEmptyException");
		
		_next--;
		
		if(_next < _size/4)
			decrease();
	}
	
	T top() const{
		return _values[_next-1];
	}
	
	stackIter begin() const {
		return {_values};
	}
	
	stackIter end() const {
		return {_values + _next};
	}
	
	std::string toString() const{
		std::ostringstream os;
		stackIter iter;
		for(iter = begin(); iter != end(); iter++) {
			os << *(*iter) << " ";
		}
		return os.str();
	}
	
};

template <typename T2>
std::ostream& operator<<(std::ostream& os, const Stack<T2> &s) {
	os << s.toString();
	return os;
}

#endif