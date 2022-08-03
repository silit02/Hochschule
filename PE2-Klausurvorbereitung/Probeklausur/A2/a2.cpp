#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	map<string, int> cars;
	ifstream fp(argv[1]);
	string line;
	
	if(!fp)
		return 1;
	
	getline(fp, line);
	while(!fp.eof()) {
		int pos = line.find(":");
		string car = line.substr(0, pos);
		cars[car] += atoi((line.substr(pos+1).c_str()));
		getline(fp, line);
	}
	
	map<string, int>::iterator i;
	for(i = cars.begin(); i != cars.end(); i++)
		cout << i->first << ":" << i->second << endl;
}