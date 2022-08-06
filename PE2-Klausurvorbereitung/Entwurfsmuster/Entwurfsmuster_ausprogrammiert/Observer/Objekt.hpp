#ifndef __OBJEKT__
#define __OBJEKT__

#include <sstream>
#include "Logger.hpp"

template<class T>
class Liste{
private:
    T *_values;
    size_t _length;
    size_t _size;

    Logger *logger;

    bool isFull();
    bool degradeable();

    void upgrade();
    void degrade();

public:
    Liste();
    ~Liste();
    void printlist();
    void add_item(T value);
    void pop_item();
    void registerLogger(Logger *L);
};



// =========================================== Konstruktor & Destruktor
template<typename T>
Liste<T>::Liste() {
    cout << "Konstruktor aufgerufen" << endl;

    _values = new T[10];
    _length = 0;
    _size = 10;
}

template<typename T>
Liste<T>::~Liste(){
    delete[] _values;
}
// ===========================================

// =========================================== Add and Remove
template<typename T>
void Liste<T>::add_item(T value) {
    _values[_length] = value;
    _length++;

    ostringstream s;
    s << "Added value " << value;
    cout << s.str() << endl;
    this->logger->addMessage(s.str());

    if(isFull()){
        upgrade();
    }
}

template<typename T>
void Liste<T>::pop_item() {
    _length--;

    ostringstream s;
    s << "Popped Item with Value " << _values[_length];
    this->logger->addMessage(s.str());

    if(degradeable()){
        degrade();
    }
}
// ===========================================

// =========================================== Upgrading and Degrading
template<typename T>
bool Liste<T>::isFull(){
    return (_length == _size);
}

template<typename T>
void Liste<T>::upgrade(){
    T *values = new T[_size * 2];

    for(size_t i=0; i< _length; i++){
        values[i] = this->_values[i];
    }

    delete[] _values;

    this->_values = values;

    ostringstream s;
    s << "Upgrading from " << _size << " to " << _size * 2;
    this->logger->addMessage(s.str());

    this->_size *= 2;
}

template<typename T>
void Liste<T>::degrade(){
    T *values = new T[_size / 2];

    for(size_t i=0; i<_length; i++){
        values[i] = _values[i];
    }

    delete[] this->_values;

    this->_values = values;

    ostringstream s;
    s << "Degrading from " << _size << " to " << _size / 2;
    this->logger->addMessage(s.str());

    this->_size /= 2;
}


template<typename T>
bool Liste<T>::degradeable(){
    return (_size > 10 && _size / 2 > _length);
}
// ===========================================


template<typename T>
void Liste<T>::printlist() {
    for(int i=0; i<_length; i++){
        cout << "Liste[" << i << "] = " << _values[i] << endl;
    }
}

template<typename T>
void Liste<T>::registerLogger(Logger *L){
    this->logger = L;
    this->logger->addMessage("Registered new Logger!");
}


#endif