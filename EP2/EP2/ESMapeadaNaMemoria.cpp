#include "ESMapeadaNaMemoria.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM *m)
{
    this-> m = m;
    dispositivos = new vector<Dispositivo *>();
}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM *m, vector<Dispositivo *> *dispositivos)
{
    this-> m = m;
    this-> dispositivos = dispositivos;
}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria()
{
    delete m;
    for (unsigned int i = 0; i < dispositivos->size(); i++)
    {
        delete dispositivos->at(i);
    }
}

MemoriaRAM *ESMapeadaNaMemoria::getMemoriaSubjacente()
{
    return m;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo *d)
{

    dispositivos->push_back(d);
}

Dado *ESMapeadaNaMemoria::ler(int posicao)
{
    if (posicao < 0 || posicao > m->getTamanho() + (int)dispositivos->size())
    {
        throw new logic_error("Posicao Invalida");
    }
    if (posicao >= 0 && posicao < m->getTamanho())
    {
        return this->getMemoriaSubjacente()->ler(posicao);
    }
    if (posicao >= this->getMemoriaSubjacente()->getTamanho())
    {
        return (*this->dispositivos)[posicao - (this->getMemoriaSubjacente()->getTamanho())]->ler();
    }
    else
    {
        throw new logic_error("Posicao Invalida");
    }
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado *d)
{
    if (posicao < 0)
    {
        throw new logic_error("Posicao Invalida");
    }
    if (posicao == 0 || posicao < (this->m->getTamanho()))
    {
        this->getMemoriaSubjacente()->escrever(posicao, d);
        return;
    }
    if (posicao >= this->getMemoriaSubjacente()->getTamanho())
    {
        this->dispositivos->at(posicao - this->getMemoriaSubjacente()->getTamanho())->escrever(d);
        return;
    }
}

vector<Dispositivo *> *ESMapeadaNaMemoria::getDispositivos()
{
    return dispositivos;
}

int ESMapeadaNaMemoria::getTamanho()
{
    int i =  m->getTamanho() + (int)dispositivos->size();
    return i;
}

void ESMapeadaNaMemoria::imprimir()
{
    this->getMemoriaSubjacente()->imprimir();
}
