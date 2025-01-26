#ifndef BANCO_DE_REGISTRADORES_H
#define BANCO_DE_REGISTRADORES_H

#include <iostream>

using namespace std;

#define QUANTIDADE_REGISTRADORES 32

class BancoDeRegistradores{
    private:
        int registrador;
        int valor;
        int *registradores = new int [QUANTIDADE_REGISTRADORES];
    public:
        BancoDeRegistradores();
        virtual ~BancoDeRegistradores();
        int getValor(int registrador);
        void setValor(int registrador, int valor);
        void imprimir(); 
};

#endif