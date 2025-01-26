#ifndef FILME_H
#define FILME_H
#include <string>
using namespace std;

class Filme {
public:
    Filme(string nome, int duracao);
    ~Filme();
    string getNome();
    void assistir(int tempo);
    int getVisualizacoes();
    int getDuracao();

    void imprimir();

protected:
    string nome;
    int duracao;
    int visualizacoes;
};

#endif // FILME_H
