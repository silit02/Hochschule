#include <iostream>
#include "strategy.hpp"
using namespace std;

int main(){
    Kontext k(new fo);

    cout << k.something() << endl;
    k.setStrategy(new ba);
    cout << k.something() << endl;
    return 0;
}