#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(int tamanho) : Memoria()
{
    this->tamanho = tamanho;
    dados = new Dado *[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        dados[i] = NULL;
    }
}

MemoriaRAM::~MemoriaRAM()
{
    for (int i = 0; i < this->getTamanho(); i++)
    {
        delete dados[i];
    }
    delete[] dados;
}

Dado *MemoriaRAM::ler(int posicao)
{
    if (posicao < 0 || posicao >= this->getTamanho())
    {
        throw new logic_error("Posicao Invalida");
    }
    return this->dados[posicao];
}

void MemoriaRAM::escrever(int posicao, Dado *d)
{
    if (posicao < 0 || posicao > this->getTamanho())
    {
        throw new logic_error("Posicao Invalida");
    }
    if (dados[posicao] != NULL)
    {
        delete dados[posicao];
    }
    dados[posicao] = d;
}

void MemoriaRAM::escrever(list<Dado *> *dados)
{
    if (dados->size() > this->getTamanho())
    {
        throw new logic_error("Atingiu o Tamanho Maximo");
    }

    list<Dado *>::iterator i = dados->begin();
    int t = 0;
    while (i != dados->end())
    {
        this->dados[t++] = (*i);
        i++;
    }
}

void MemoriaRAM::imprimir()
{

    for (int n = 0; n < this->getTamanho(); n++)
    {
        if (dados[n] != NULL)
        {
            cout << n << ":";
            dados[n]->imprimir();
            cout << endl;
        }
        else
        {
            cout << n << ":"
                 << "-" << endl;
        }
    }
}

int MemoriaRAM::getTamanho()
{
    return this->tamanho;
}