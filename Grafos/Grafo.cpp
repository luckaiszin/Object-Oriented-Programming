#include "Grafo.h"

using namespace std;

Grafo::Grafo(int tamanho)
{
    this->tamanho = tamanho;
    for (int i = 0; i < this->getTamanho(); i++)
    {
        for (int j = i; j < this->getTamanho(); j++)
        {
            cout << "elemento [" << i + 1 << "]"
                 << "[" << j + 1 << "]"
                 << ":";
            cin >> this->Adjacencia[i][j];
            this->Adjacencia[j][i] = this->Adjacencia[i][j];
        }
        this->predecessor[i] = 0;
    }
}

Grafo::~Grafo()
{
}

int Grafo::getTamanho()
{
    return this->tamanho;
}

int Grafo::getElemento(int i, int j)
{
    return this->Adjacencia[i][j];
}

int Grafo::getPredecessor(int i)
{
    return this->predecessor[i];
}

void Grafo::conecta(int i, int j)
{
    this->Adjacencia[i][j] = this->Adjacencia[j][i] = 1;
}

void Grafo::desconecta(int i, int j)
{
    this->Adjacencia[i][j] = this->Adjacencia[j][i] = 0;
}

bool Grafo::possuiAresta(int i, int j)
{

    if (this->Adjacencia[i][j] != 0)
        return 1;
    return 0;
}

int Grafo::Grau(int x)
{

    int quantidade = 0;
    for (int i = 0; i < this->getTamanho(); i++)
    {
        if (Adjacencia[x][i] != 0)
        {
            quantidade++;
        }
    }
    return quantidade;
}

bool Grafo::possuiLaco()
{

    for (int i = 0; i < this->getTamanho(); i++)
    {
        if (this->Adjacencia[i][i] == 1)
            return 1;
    }
    return 0;
}

bool Grafo::possuiCaminho(int i, int j)
{

    return this->Adjacencia[i][j];
}

void Grafo::BFS(int x)
{
}
void Grafo::imprimir()
{
    for (int i = 0; i < this->getTamanho(); i++)
    {
        for (int j = 0; j < this->getTamanho(); j++)
        {
            cout << this->getElemento(i, j) << " ";
        }
        cout << endl;
    }
}