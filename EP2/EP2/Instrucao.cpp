#include "Instrucao.h"

using namespace std;

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato,
                     int funcao) : Dado(opcode)
{
    this->opcode = opcode;
    this->origem1 = origem1;
    this->origem2 = origem2;
    this->destino = destino;
    this->imediato = imediato;
    this->funcao = funcao;
}

Instrucao::~Instrucao()
{
}

int Instrucao::getOpcode()
{
    return this->opcode;
}

int Instrucao::getOrigem1()
{

    return this->origem1;
}
int Instrucao::getOrigem2()
{
    return this->origem2;
}
int Instrucao::getDestino()
{
    return this->destino;
}
int Instrucao::getImediato()
{
    return this->imediato;
}
int Instrucao::getFuncao()
{
    return this->funcao;
}

void Instrucao::imprimir()
{
    cout << "Instrucao" << this->getOpcode();
}

Instrucao *Instrucao::criarLW(int destino, int imediato)
{
    Instrucao *I = new Instrucao(LW, 0, 0, destino, imediato, 0);
    return I;
}

Instrucao *Instrucao::criarSW(int destino, int imediato)
{
    Instrucao *I = new Instrucao(SW, 0, 0, destino, imediato, 0);
    return I;
}

Instrucao *Instrucao::criarJ(int imediato)
{
    Instrucao *I = new Instrucao(J, 0, 0, 0, imediato, 0);
    return I;
}

Instrucao *Instrucao::criarBNE(int origem1, int origem2, int imediato)
{
    Instrucao *I = new Instrucao(BNE, origem1, origem2, 0, imediato, 0);
    return I;
}

Instrucao *Instrucao::criarBEQ(int origem1, int origem2, int imediato)
{
    Instrucao *I = new Instrucao(BEQ, origem1, origem2, 0, imediato, 0);
    return I;
}

Instrucao *Instrucao::criarADD(int destino, int origem1, int origem2)
{
    Instrucao *I = new Instrucao(TIPO_R, origem1, origem2, destino, 0, FUNCAO_ADD);
    return I;
}

Instrucao *Instrucao::criarSUB(int destino, int origem1, int origem2)
{
    Instrucao *I = new Instrucao(TIPO_R, origem1, origem2, destino, 0, FUNCAO_SUB);
    return I;
}

Instrucao *Instrucao::criarMULT(int origem1, int origem2)
{
    Instrucao *I = new Instrucao(TIPO_R, origem1, origem2, 0, 0, FUNCAO_MULT);
    return I;
}

Instrucao *Instrucao::criarDIV(int origem1, int origem2)
{
    Instrucao *I = new Instrucao(TIPO_R, origem1, origem2, 0, 0, FUNCAO_DIV);
    return I;
}