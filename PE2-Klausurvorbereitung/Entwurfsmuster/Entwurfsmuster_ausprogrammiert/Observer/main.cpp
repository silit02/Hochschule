#include <iostream>
#include "Objekt.hpp"
#include "Logger.hpp"

using namespace std;

int main(void){

    Liste<int> list;
    Logger logger;

    list.registerLogger(&logger);

    for(size_t i=0; i<20; i++){
        list.add_item((int)i);
    }

    for(size_t i=0; i<10; i++){
        list.pop_item();
    }

    logger.printLog();


    return 0;
}