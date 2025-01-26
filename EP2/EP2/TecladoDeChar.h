#ifndef TECLADODECHAR_H
#define TECLADODECHAR_H

#include "Teclado.h"
#include <iostream>

using namespace std;

class TecladoDeChar : public Teclado {
    public:
        TecladoDeChar();
        virtual ~TecladoDeChar();
        Dado* ler();
};

#endif