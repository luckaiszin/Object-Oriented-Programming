#include "MemoriaDeDados.h"

using namespace std;

MemoriaDeDados::MemoriaDeDados(int tamanho)
{
    this->tamanho = tamanho;
    dados = new Dado *[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        dados[i] = NULL;
    }
}

MemoriaDeDados::~MemoriaDeDados()
{
    cout << "Destruido" << endl;
    for (int i = 0; i < this->tamanho; i++)
    {
        delete dados[i];
    }
    delete[] dados;
}

int MemoriaDeDados::getTamanho()
{
    return this->tamanho;
}

Dado *MemoriaDeDados::ler(int posicao)
{
    if (posicao < 0 || posicao > this->tamanho)
    {
        return NULL;
    }
    else
        return dados[posicao];
}

bool MemoriaDeDados::escrever(int posicao, Dado *d)
{
    if (dados[posicao] == NULL)
    {
        dados[posicao] = d;
        return 1;
    }
    else if (posicao > this->tamanho)
    {
        return 0;
    }
    else
    {
        delete dados[posicao];
        dados[posicao] = d;
    }
}

void MemoriaDeDados::imprimir()
{
    for (int n = 0; n < this->tamanho; n++)
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