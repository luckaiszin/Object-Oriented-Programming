#include "MemoriaDeInstrucoes.h"

using namespace std;

MemoriaDeInstrucoes::MemoriaDeInstrucoes(int tamanho){
    this->tamanho = tamanho;
    r = new Instrucao*[tamanho];
    for(int i=0; i<tamanho;i++){
        r[i]=NULL;
    }
}

MemoriaDeInstrucoes::~MemoriaDeInstrucoes(){
    cout<<"Destruido"<<endl;
    for(int i=0;i<this->tamanho;i++){
        delete r[i];
    }
    delete [] r;
}

int MemoriaDeInstrucoes::getTamanho(){
    return this->tamanho;
}

Instrucao *MemoriaDeInstrucoes::ler(int posicao){
    return r[posicao];
}

bool MemoriaDeInstrucoes::escrever(int posicao, Instrucao* d){
    if(r[posicao]==NULL){
        r[posicao] = d; 
        return 1;
    }
    else if(posicao>this->tamanho){
        return 0;
    }
    else{
        delete r[posicao];
        r[posicao] = d;
    }
}