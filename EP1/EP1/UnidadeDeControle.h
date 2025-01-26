#ifndef UNIDADE_DE_CONTROLE_H
#define UNIDADE_DE_CONTROLE_H

#include <iostream>
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"
#include "BancoDeRegistradores.h"

class UnidadeDeControle{
    private:
        int pc;
        BancoDeRegistradores* registradores;
        MemoriaDeInstrucoes* instrucoes;
        MemoriaDeDados* dados;
    public:
        UnidadeDeControle(BancoDeRegistradores* registradores,
        MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados);
        virtual ~UnidadeDeControle();
        BancoDeRegistradores* getBancoDeRegistradores();
        MemoriaDeDados* getMemoriaDeDados();
        MemoriaDeInstrucoes* getMemoriaDeInstrucoes();
        int getPC();
        void setPC(int pc);
        void executarInstrucao();
};

#endif