#ifndef FILME_H
#define FILME_H

#include <string>
using namespace std;

class Filme
{
private:
  string nome;
  int duracao;

public:
  void imprimir();
  string getNome();
  int getDuracao();
  void setNome(string nome);
  void setDuracao(int duracao);
};

#endif