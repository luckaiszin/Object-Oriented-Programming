#include "UnidadeDeControle.h"
#include "Memoria.h"
#include "Instrucao.h"

using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores *registradores, Memoria *memoria)
{
    this->registradores = registradores;
    this->memoria = memoria;
    this->pc = 0;
}

UnidadeDeControle::~UnidadeDeControle()
{
    delete this->registradores;
    delete this->memoria;
}

BancoDeRegistradores *UnidadeDeControle::getBancoDeRegistradores()
{
    return this->registradores;
}

Memoria *UnidadeDeControle::getMemoria()
{
    return this->memoria;
}

int UnidadeDeControle::getPC()
{
    return this->pc;
}

void UnidadeDeControle::setPC(int pc)
{
    this->pc = pc;
}

void UnidadeDeControle::executarInstrucao()
{

    Instrucao *instrucao = dynamic_cast<Instrucao *>(getMemoria()->ler(pc));
    if (instrucao == NULL)
    {
        pc++;
        return;
    }

    int opcode = instrucao->getOpcode();
    int origem1 = instrucao->getOrigem1();
    int origem2 = instrucao->getOrigem2();
    int destino = instrucao->getDestino();
    int imediato = instrucao->getImediato();
    int funcao = instrucao->getFuncao();

    if (opcode == Instrucao::LW)
    {

        Dado *K = getMemoria()->ler(imediato);

        if (K == NULL)
            getBancoDeRegistradores()->setValor(destino, 0);

        getBancoDeRegistradores()->setValor(destino, K->getValor());
        pc++;
        return;
    }

    if (opcode == Instrucao::SW)
    {
        getMemoria()->escrever(imediato, new Dado(getBancoDeRegistradores()->getValor(instrucao->getDestino())));
        // getBancoDeRegistradores()->setValor(imediato, getMemoria()->ler(destino)->getValor());
        pc++;
        return;
    }

    if (opcode == Instrucao::J)
    {
        setPC(imediato);
        return;
    }

    if (opcode == Instrucao::BNE)
    {
        if (getBancoDeRegistradores()->getValor(origem1) != getBancoDeRegistradores()->getValor(origem2))
            setPC(imediato);

        else
            pc++;
        return;
    }

    if (opcode == Instrucao::BEQ)
    {
        if (getBancoDeRegistradores()->getValor(origem1) == getBancoDeRegistradores()->getValor(origem2))
            setPC(imediato);

        else
            pc++;
        return;
    }

    if (opcode == Instrucao::TIPO_R)
    {

        if (funcao == Instrucao::FUNCAO_ADD)
        {
            getBancoDeRegistradores()->setValor(destino, getBancoDeRegistradores()->getValor(origem1) + getBancoDeRegistradores()->getValor(origem2));
            pc++;
        }

        if (funcao == Instrucao::FUNCAO_SUB)
        {
            getBancoDeRegistradores()->setValor(destino, getBancoDeRegistradores()->getValor(origem1) - getBancoDeRegistradores()->getValor(origem2));
            pc++;
        }

        if (funcao == Instrucao::FUNCAO_MULT)
        {
            getBancoDeRegistradores()->setValor(24, getBancoDeRegistradores()->getValor(origem1) * getBancoDeRegistradores()->getValor(origem2));
            pc++;
        }

        if (funcao == Instrucao::FUNCAO_DIV)
        {
            getBancoDeRegistradores()->setValor(24, getBancoDeRegistradores()->getValor(origem1) / getBancoDeRegistradores()->getValor(origem2));
            getBancoDeRegistradores()->setValor(25, getBancoDeRegistradores()->getValor(origem1) % getBancoDeRegistradores()->getValor(origem2));
            pc++;
        }

        return;
    }
}