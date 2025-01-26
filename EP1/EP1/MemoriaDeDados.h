#ifndef MEMORIA_DE_DADOS_H
#define MEMORIA_DE_DADOS_H

#include <iostream>
#include "Dado.h"

class MemoriaDeDados{
    private:
       int tamanho;
       int posicao;
       Dado **dados;
    
    public:
        MemoriaDeDados(int tamanho);
        virtual ~MemoriaDeDados();
        int getTamanho();
        Dado* ler(int posicao);
        bool escrever(int posicao, Dado* d);
        void imprimir(); 
};

#endif