#include "Filme.h"
#include "Lancamento.h"
#include "ListaDeFilmes.h"

void teste1()
{
    Filme *F = new Lancamento(12, 2003, "Sonic 2", 110);
    /* Filme *F = new Filme("Sonic 2", 110);
    Lancamento *L = static_cast<Lancamento*>(F); */
    Lancamento *L = static_cast<Lancamento *>(F);
    L->imprimir();
    delete L;
}

void teste2()
{
    Filme *F1 = new Filme("Pequena Sereia", 83);
    Lancamento *F2 = new Lancamento(12, 2003, "Sonic 2", 110);
    ListaDeFilmes *Lista = new ListaDeFilmes(2);
    Lista->adicionar(F1);
    Lista->adicionar(F2);
    Lista->imprimir();
    Lista->remover(F1);
    Lista->imprimir();
    delete Lista;
    delete F1;
    delete F2;
}

int main()
{
    teste2(); // Substitua pelo teste que deseja chamar
    return 0;
}
