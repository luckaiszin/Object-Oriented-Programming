#ifndef MEMORIA_RAM_H
#define MEMORIA_RAM_H

#include "Memoria.h"
#include <list>
#include <algorithm>
using namespace std;

class MemoriaRAM : public Memoria{
private:
    Dado **dados;
protected:
    int tamanho;
public:
    MemoriaRAM(int tamanho);
    virtual ~MemoriaRAM();
    virtual Dado* ler(int posicao);
    virtual void escrever(int posicao, Dado* d);
    virtual void escrever(list<Dado *> *dados);
    int getTamanho();
    virtual void imprimir();
};

#endif