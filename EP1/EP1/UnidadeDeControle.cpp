#include "UnidadeDeControle.h"

using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores,MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados){
    
    this->registradores = registradores;
    this->instrucoes = instrucoes;
    this->dados = dados;
    this->pc=0;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete this->registradores;
    delete this->instrucoes;
    delete this->dados;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return this->registradores;
}

MemoriaDeDados* UnidadeDeControle::getMemoriaDeDados(){
    return this->dados;
}

MemoriaDeInstrucoes* UnidadeDeControle::getMemoriaDeInstrucoes(){
    return this->instrucoes;
}

int UnidadeDeControle::getPC(){
    return this->pc;
}

void UnidadeDeControle::setPC(int pc){
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao(){

    if(this->instrucoes == NULL){
        pc+=1;
    }
    else if 

}