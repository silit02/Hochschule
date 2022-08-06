#include "strategy.hpp"
using namespace std;

string fo::foo() {
    return "fooooooooooooooooooooo";
}

string ba::foo(){
    return "baaaaaaaaaaaaaaaaaaaaa";
}

Kontext::Kontext(Strategy* strat) {
    _strat = strat;
}

void Kontext::setStrategy(Strategy* strat){
    _strat = strat;
}

string Kontext::something(){
    return _strat->foo();
}