#ifndef MONITORDECHAR_H
#define MONITORDECHAR_H

#include "Monitor.h"
#include <iostream>

using namespace std;

class MonitorDeChar : public Monitor {
    public:
        MonitorDeChar();
        virtual ~MonitorDeChar();
        Dado* ler();
        void escrever(Dado *d);
};

#endif