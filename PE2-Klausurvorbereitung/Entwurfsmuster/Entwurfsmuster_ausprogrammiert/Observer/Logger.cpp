#include "Logger.hpp"

#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

void Logger::addMessage(string message){
    log.push_back(message);
}

void Logger::printLog(){
    size_t i = 0;
    for(auto iter = log.begin(); iter != log.end(); iter++){
        cout << "Log[" << i << "] = " << *iter << endl;
        i++;
    }
}