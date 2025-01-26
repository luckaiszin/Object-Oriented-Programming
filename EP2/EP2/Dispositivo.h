#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <iostream>
#include "Dado.h"

class Dispositivo {
    public:
        Dispositivo();
        virtual ~Dispositivo();
        virtual Dado* ler() = 0;
        virtual void escrever(Dado *d) = 0;
};

#endif