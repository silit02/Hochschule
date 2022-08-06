#include <iostream>
#include "composite.hpp"
using namespace std;

int main(){
    Component* a = A::exemplar();
    Component* b = B::exemplar();
    Component* c = C::exemplar();
    Composite comp;

    comp.add(a);
    comp.add(c);

    cout << "a: " << a->getType() << endl;
    cout << "b: " << b->getType() << endl;
    cout << "c: " << c->getType() << endl;
    cout << "comp: " << comp.getType() << endl;

    comp.add(b);
    comp.remove(c);

    cout << "comp: " << comp.getType() << endl;

    Composite co;
    co.add(b);
    co.add(c);
    comp.add(&co);
    
    cout << "comp: " << comp.getType() << endl;
}