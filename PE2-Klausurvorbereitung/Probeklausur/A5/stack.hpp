#ifndef _STACK_HPP
#define _STACK_HPP

class Stack{
protected:
	int pos, size, *values;
	bool isFull();
	
public:
	Stack(int s = 8);
	~Stack();
	bool isEmpty();
	void push(int val);
	int top();
	void pop();
};

Stack::Stack(int s){
	pos = 0;
	size = s;
	values = new int[s];
}

Stack::~Stack(){
	delete[] values;
}

bool Stack::isFull(){
	if(pos >= size)
		return true;
	return false;
}

bool Stack::isEmpty(){
	if(pos==0)
		return true;
	return false;
}

void Stack::push(int val){
	if(isFull())
		throw "Stack is Full";
	values[pos++] = val;
}

int Stack::top(){
	if(isEmpty())
		throw "Stack is Empty";
	return values[pos-1];
}

void Stack::pop(){
	if(isEmpty())
		throw "Stack is empty";
	pos--;
}

#endif