#include "composite.hpp"
#include <iostream>
using namespace std;


string A::getType(){
    return "A";
}

Component* A::_exemplar = nullptr;

Component* A::exemplar(){
    if(A::_exemplar == nullptr)
        _exemplar = new A;
    return A::_exemplar;
}

string B::getType(){
    return "B";
}

Component* B::_exemplar = nullptr;

Component* B::exemplar(){
    if(B::_exemplar == nullptr)
        _exemplar = new B;
    return B::_exemplar;
}

string C::getType(){
    return "C";
}

Component* C::_exemplar = nullptr;

Component* C::exemplar(){
    if(C::_exemplar == nullptr)
        _exemplar = new C;
    return C::_exemplar;
}

string Composite::getType(){
    string s("");
    for(Component* c:_childs){
        s+=c->getType();
    }
    return s;
}

void Composite::add(Component *c){
    _childs.push_back(c);
    cout << c->getType() << " added to " << this->getType() << endl;
}

void Composite::remove(Component *c){
    vector<Component*>::iterator iter = _childs.begin();
    while(iter != _childs.end()){
        if(*iter == c){
            _childs.erase(iter);
            break;
        }
        iter++;
    }
    cout << c->getType() << " removed from " << this->getType() << endl; 
}

Component* Composite::child(int id){
    return _childs.at(id);
}