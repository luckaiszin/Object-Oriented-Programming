#ifndef ES_MAPEADA_NA_MEMORIA_H
#define ES_MAPEADA_NA_MEMORIA_H

#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>

class ESMapeadaNaMemoria: public Memoria{
private:
    MemoriaRAM* m;
    vector<Dispositivo*>* dispositivos;
    
public:
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
    virtual ~ESMapeadaNaMemoria();
    virtual MemoriaRAM* getMemoriaSubjacente();
    virtual Dado* ler(int posicao);
    virtual void escrever(int posicao, Dado* d);
    virtual void adicionar(Dispositivo* d);
    virtual vector<Dispositivo*>* getDispositivos(); 
    int getTamanho();
    virtual void imprimir();
};

#endif