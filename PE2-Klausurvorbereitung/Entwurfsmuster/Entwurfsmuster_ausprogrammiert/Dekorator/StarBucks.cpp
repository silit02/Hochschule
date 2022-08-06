#include <iostream>

using namespace std;

class Kaffee {
public:
    virtual ~Kaffee() {};
    virtual int preis() = 0;
    virtual string rechnung() = 0;
};


class Espresso : public Kaffee {
public:
    int preis() override{
        return 200;
    }

    string rechnung() override{
        return "Espresso:  200ct\n";
    }
};


class Cappuccino : public Kaffee {
public:
    int preis() override{
        return 250;
    }

    string rechnung() override{
        return "Cappuccino: 250\n";
    }
};

class Zutat : public Kaffee {
protected:
    Kaffee *dekoriert;

public:
    Zutat(Kaffee *K){
        dekoriert = K;
    }
};

class Milchschaum : public Zutat {
public:
    Milchschaum(Kaffee *K): Zutat(K) {}
    ~Milchschaum() {
        delete dekoriert;
    }

    int preis() override{
        return dekoriert->preis() + 50;
    }
    string rechnung() override{
        return dekoriert->rechnung() + "Milchschaum: 50\n";
    }
};

class Zucker : public Zutat {
public:
    Zucker(Kaffee *K) : Zutat(K){}
    ~Zucker(){
        delete dekoriert;
    }
    int preis(){
        return dekoriert->preis() + 20;
    }
    string rechnung(){
        return dekoriert->rechnung() + "Zucker:      20\n";
    }
};

//  Essen *E = new Parmesan(new Bolognese(new Spaghetti))

int main(void){

    Kaffee *nr1 = new Zucker(new Espresso());
    cout << "Nr1:" << endl;    
    cout << "Rechnung:\n" <<nr1->rechnung() << endl;
    cout << "Preis: " << nr1->preis() << endl;

	cout << endl;

    Kaffee *nr2 = new Zucker(new Milchschaum(new Espresso()));
    cout << "Nr2:" << endl;
    cout << "Rechnung:\n " << nr2->rechnung()  << endl;
    cout << "Preis: "    << nr2->preis()     << endl;

    return 0;
}
