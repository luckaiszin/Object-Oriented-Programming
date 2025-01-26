#ifndef CATALOGO_H
#define CATALOGO_H
#include "Filme.h"
#include "Lancamento.h"

class Catalogo {
public:
    //Declare os metodos pedidos no enunciado
    Catalogo(int tamanhoMaximo);
    ~Catalogo();
    bool adicionar(Filme *f);
    bool adicionar(string categoria);
    int getDuracaoTotal();
    int getTotalDeVisualizacoes();
    Filme** getFilmes();
    string* getCategorias();
    Lancamento** getLancamentos(int &quantidadeLancamentos); 

    void imprimir();


private:
    int tamanhoMaximo;
    Filme** filmes;
    int quantidadeFilmes;
    string* categorias;
    int quantidadeCategorias;
};

#endif // CATALOGO_H
