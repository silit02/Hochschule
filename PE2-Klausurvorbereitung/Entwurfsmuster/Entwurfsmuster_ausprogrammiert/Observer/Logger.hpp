#ifndef __LOGGER__
#define __LOGGER__

#include <vector>
#include <iostream>

using namespace std;

class Logger {
    private:
        vector<string> log;
    public:
        void addMessage(string message);
        void printLog();
};

#endif