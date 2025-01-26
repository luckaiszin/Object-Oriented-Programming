#ifndef MONITOR_H
#define MONITOR_H

#include "Dispositivo.h"
#include <iostream>

using namespace std;

class Monitor : public Dispositivo {
    public:
        Monitor();
        virtual ~Monitor();
        Dado* ler();
        void escrever(Dado *d);


};

#endif