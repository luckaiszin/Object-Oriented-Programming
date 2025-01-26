#ifndef BANCO_DE_REGISTRADORES_H
#define BANCO_DE_REGISTRADORES_H
#define QUANTIDADE_REGISTRADORES 32
#include <iostream>

using namespace std;

class BancoDeRegistradores
{
private:
    int *registradores = new int[QUANTIDADE_REGISTRADORES];

public:
    BancoDeRegistradores();
    virtual ~BancoDeRegistradores();
    virtual int getValor(int registrador);
    virtual void setValor(int registrador, int valor);
    virtual void imprimir();
};

#endif