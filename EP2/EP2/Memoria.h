#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include <stdexcept>
#include "Dado.h"

class Memoria{
protected:
    int tamanho;
public:
    Memoria();
    virtual ~Memoria();
    virtual int getTamanho() = 0;
    virtual Dado* ler(int posicao) = 0;
    virtual void escrever(int posicao, Dado* d) = 0;
    virtual void imprimir() = 0;
};

#endif