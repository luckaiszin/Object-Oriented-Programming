#ifndef TECLADO_H
#define TECLADO_H
#include "Dispositivo.h"

class Teclado : public Dispositivo {
    public:
        Teclado();
        virtual ~Teclado();
        virtual Dado* ler();
        virtual void escrever(Dado *d);
};

#endif