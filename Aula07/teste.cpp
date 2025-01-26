#include <iostream>
#include "Catalogo.h"
#include "Lancamento.h"

using namespace std;

void teste1()
{
    Catalogo *C = new Catalogo(2);
    Filme *F = new Filme("Madagascar", 100);
    F->assistir(20);
    F->assistir(30);
    F->assistir(50);
    C->adicionar(F);
    C->adicionar("Animacao");
    C->imprimir();
    delete C;
    delete F;
}

void teste2()
{
    Catalogo *C = new Catalogo(2);
    Filme *F1 = new Filme("Madagascar", 100);
    F1->assistir(20);
    F1->assistir(30);
    F1->assistir(50);
    C->adicionar(F1);
    C->adicionar("Animacao");
    Filme *F2 = new Lancamento("Tempos Modernos", 100);
    Lancamento *L = static_cast<Lancamento *>(F2);
    //// Passo 2: ponteiro de Filme
    L->assistir(20);
    L->assistir(30);
    L->assistir(50);
    C->adicionar(L);
    C->imprimir();
    delete C;
    delete F1;
    delete L;
}

void teste3()
{
    Catalogo *C = new Catalogo(2);
}

int main()
{
    teste2(); // Escolha o teste do exercicio a ser testado
    return 0;
}
