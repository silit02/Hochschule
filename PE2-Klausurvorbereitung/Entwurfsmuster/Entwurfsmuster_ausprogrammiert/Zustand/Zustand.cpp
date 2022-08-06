#include <iostream>

using namespace std;

class Automat;
class Geldeingabe;
class Produkteingabe;
class Produktausgabe;

class Zustand {
public:
    Automat *_Automat;
    virtual void anzeigen(){}
    virtual void reagieren(){}
    virtual ~Zustand() {}
};

class Produktwahl : public Zustand {
public:
    static Produktwahl* _exemplar;
    
    static Produktwahl* exemplar(Automat *A){
        if(Produktwahl::_exemplar == nullptr){
            Produktwahl::_exemplar = new Produktwahl();
            Produktwahl::_exemplar->_Automat = A;
        }
        return Produktwahl::_exemplar;
    }
    
    void anzeigen(){
        cout << "Produktauswahl" << endl;
    }
    void reagieren(){
        _Automat->current = Geldeingabe::exemplar(_Automat);
    }
};
Produktwahl* Produktwahl::_exemplar = nullptr;

class Geldeingabe : public Zustand {
public:
    static Geldeingabe* _exemplar;

    static Geldeingabe* exemplar(Automat *A){
        if(Geldeingabe::_exemplar == nullptr){
            Geldeingabe::_exemplar = new Geldeingabe();
            Geldeingabe::_exemplar->_Automat = A;
        }
        return Geldeingabe::_exemplar;
    }

    void anzeigen(){
        cout << "Geldeingabe" << endl;
    }
    void reagieren(){
        _Automat->current = Produktausgabe::exemplar(_Automat);
    }
};
Geldeingabe* Geldeingabe::_exemplar = nullptr;

class Produktausgabe : public Zustand {
public:
    static Produktausgabe* _exemplar;

    static Produktausgabe* exemplar(Automat *A){
        if(Produktausgabe::_exemplar == nullptr){
            Produktausgabe::_exemplar = new Produktausgabe();
            Produktausgabe::_exemplar->_Automat = A;
        }
        return Produktausgabe::_exemplar;
    }

    void anzeigen(){
        cout << "Produktausgabe" << endl;
    }
    void reagieren(){
        _Automat->current = nullptr;
    }
};
Produktausgabe* Produktausgabe::_exemplar = nullptr;


class Automat {
public:
    Zustand* current;

    Automat(){
        Automat::current = Produktwahl::exemplar(this);
    }

    void aktion(){
        current->anzeigen();
    }

    void reaktion(){
        current->reagieren();
    }  

};


int main(void){

    Automat Zigaretten_Automat;

    while(Zigaretten_Automat.current != nullptr){
        Zigaretten_Automat.aktion();
        Zigaretten_Automat.reaktion();
    }

    return 0;
}