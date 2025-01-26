#ifndef UNIDADEDECONTROLE_H
#define UNIDADEDECONTROLE_H
#include <iostream>
#include "Memoria.h"
#include "BancoDeRegistradores.h"

using namespace std;

class UnidadeDeControle{
private:
    int pc;
    BancoDeRegistradores* registradores;
    Memoria *memoria;
    
public:
    UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
    virtual ~UnidadeDeControle();
    
    virtual BancoDeRegistradores* getBancoDeRegistradores();
    virtual Memoria* getMemoria();
    virtual int getPC();
    virtual void setPC(int pc);
    virtual void executarInstrucao();
};

#endif