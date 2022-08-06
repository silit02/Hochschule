#include <iostream>

class Singleton
{
    private:
        /* Instanz statisch speichern. */
        static Singleton* instance;

        /* Privater Konstruktor */
        Singleton();

    public:
        /* Statische methode */
        static Singleton* getInstance();
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

/* Default Konstruktor leer räumen */
Singleton::Singleton(){}

int main()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance(); // Ok
    Singleton* r = Singleton::getInstance();

    /* The addresses will be the same. */
    std::cout << "Addresse von S: " << s << std::endl;
    std::cout << "Addresse von R: " << r << std::endl;
}