#include "BancoDeRegistradores.h"

using namespace std;

BancoDeRegistradores::BancoDeRegistradores(){

    for(int i=0;i<QUANTIDADE_REGISTRADORES;i++){
        registradores[i]= 0;
    }
}

BancoDeRegistradores::~BancoDeRegistradores(){
    cout<<"Destruido"<<endl;
    delete [] registradores;
}

int BancoDeRegistradores::getValor(int registrador){

    if(registrador<0 || registrador>QUANTIDADE_REGISTRADORES){
        return 0;
    }
    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    
    for(int i=0;i<QUANTIDADE_REGISTRADORES;i++){
        cout<<i<<":"<<registradores[i]<<endl;
    }
}