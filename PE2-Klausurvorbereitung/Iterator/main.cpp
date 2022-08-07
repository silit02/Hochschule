#include <iostream>
#include "Tstack.hpp"
using namespace std;

int main() {
	Stack<int> s;
	s.push(4);
	s.push(3);
	s.push(2);
	
	cout << s << endl;
	
	return 0;
}