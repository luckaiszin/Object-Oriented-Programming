#ifndef GRAFO_H
#define GRAFO_H

#define MAX 10

#include <iostream>

class Grafo
{
private:
    int tamanho;
    int Adjacencia[MAX][MAX];
    int predecessor[MAX];

public:
    Grafo(int tamanho);
    ~Grafo();
    int getTamanho();
    int getPredecessor(int i);
    int getElemento(int i, int j);
    void conecta(int i, int j);
    void desconecta(int i, int j);
    bool possuiAresta(int i, int j);
    int Grau(int x);
    bool possuiLaco();
    bool possuiCaminho(int i, int j);
    void BFS(int x);
    void imprimir();
};

#endif