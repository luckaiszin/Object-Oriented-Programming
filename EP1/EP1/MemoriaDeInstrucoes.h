#ifndef MEMORIA_DE_INSTRUCOES_H
#define MEMORIA_DE_INSTRUCOES_H

#include <iostream>
#include "Instrucao.h"

class MemoriaDeInstrucoes{
    private:
        Instrucao **r;
        int tamanho;
        int posicao;
    public:
        MemoriaDeInstrucoes(int tamanho);
        virtual ~MemoriaDeInstrucoes();
        int getTamanho();
        Instrucao* ler(int posicao);
        bool escrever(int posicao, Instrucao* d);
};

#endif