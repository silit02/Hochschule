#include <iostream>

using namespace std;

class AttackBehaviour {
    public:
        virtual void performAttack() = 0;
        virtual ~AttackBehaviour() {};
};

class AxeAttack : public AttackBehaviour {
    public:
        virtual void performAttack(){
            cout << "Axt-Attacke!!" << endl;
        }
};

class SwordAttack : public AttackBehaviour {
    public:
        virtual void performAttack(){
            cout << "Schwert-Attacke!!" << endl;
        }
};

class FireAttack : public AttackBehaviour {
    public:
        virtual void performAttack(){
            cout << "Feuer-Attacke!!" << endl;
        }
};

class Character {
    private:
        
        int _damage;
        AttackBehaviour* _behaviour;
    
    public:
        // Wegen << überladen
        string _name;

        Character(string name, int damage, AttackBehaviour *behaviour){
            _name = name;
            _damage = damage;
            _behaviour = behaviour;
        }

        void attack(){
            cout << _name << ": ";
            this->_behaviour->performAttack();
        }

        
};

// Aus spaß gemacht
ostream& operator<<(ostream& os, Character c){
    os << c._name;
    return os;
}


int main(void){

    AxeAttack   Axt;
    SwordAttack Schwert;
    FireAttack  Feuer;

    Character Zoltan("Zoltan", 30, &Axt);
    Character Triss("Triss", 10, &Feuer);
    Character Gerald("Gerald", 20, &Schwert);

    cout << Zoltan << endl;

    Zoltan.attack();
    Triss.attack();
    Gerald.attack();

    return 0;
}