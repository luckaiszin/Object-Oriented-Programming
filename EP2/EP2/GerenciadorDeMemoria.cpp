#include "GerenciadorDeMemoria.h"
#include "Instrucao.h"

GerenciadorDeMemoria::GerenciadorDeMemoria()
{
}

GerenciadorDeMemoria::~GerenciadorDeMemoria()
{
}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM *m)
{

    int x = 0;
    int imediato;
    int destino;
    int origem1;
    int origem2;
    int n;
    string e;

    input.open(arquivo);
    if (input.fail())
    {
        throw new runtime_error("a");
    }

    input >> n;
    if (n > m->getTamanho())
    {
        throw new runtime_error("b");
    }
    while (input && x < m->getTamanho())
    {
        input >> e;
        if (e == "D")
        {
            input >> n;
            Dado *D = new Dado(n);
            m->escrever(x++, D);
            continue;
        }
        else
        {
            if (e == "LW")
            {
                input >> destino;
                input >> imediato;

                m->escrever(x++, Instrucao::criarLW(destino, imediato));
                continue;
            }
            if (e == "SW")
            {
                input >> destino;
                input >> imediato;
                Instrucao *I = Instrucao::criarSW(destino, imediato);
                m->escrever(x++, I);
                continue;
            }
            if (e == "J")
            {
                input >> imediato;
                Instrucao *I = Instrucao::criarJ(imediato);
                m->escrever(x++, I);
                continue;
            }
            if (e == "BNE")
            {
                input >> origem1;
                input >> origem2;
                input >> imediato;
                Instrucao *I = Instrucao::criarBNE(origem1, origem2, imediato);
                m->escrever(x++, I);
                continue;
            }
            if (e == "BEQ")
            {
                input >> origem1;
                input >> origem2;
                input >> imediato;
                Instrucao *I = Instrucao::criarBEQ(origem1, origem2, imediato);
                m->escrever(x++, I);
                continue;
            }
            if (e == "ADD")
            {
                input >> destino;
                input >> origem1;
                input >> origem2;
                Instrucao *I = Instrucao::criarADD(destino, origem1, origem2);
                m->escrever(x++, I);
                continue;
            }
            if (e == "SUB")
            {
                input >> destino;
                input >> origem1;
                input >> origem2;
                m->escrever(x++, Instrucao::criarSUB(destino, origem1, origem2));
                continue;
            }
            if (e == "MULT")
            {
                input >> origem1;
                input >> origem2;
                Instrucao *I = Instrucao::criarMULT(origem1, origem2);
                m->escrever(x++, I);
                continue;
            }
            if (e == "DIV")
            {
                input >> origem1;
                input >> origem2;
                Instrucao *I = Instrucao::criarDIV(origem1, origem2);
                m->escrever(x++, I);
                continue;
            }
            if (e == "-")
            {
                m->escrever(x++, NULL);
                continue;
            }
        }
    }
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM *m)
{

    output.open(arquivo);

    if (output.fail())
    {
        throw new runtime_error("d");
    }
    else
    {
        output << m->getTamanho() << endl;
    }

    for (int i = 0; i < m->getTamanho(); i++)
    {

        Dado *D = m->ler(i);
        Instrucao *In = dynamic_cast<Instrucao *>(D);

        if (m->ler(i) == NULL)
        {
            output << "-" << endl;
            continue;
        }

        else if (In != NULL)
        { ///////////////
            if (In->getOpcode() == 0)
            {
                if (In->getFuncao() == Instrucao::FUNCAO_ADD)
                {
                    output << "ADD " << In->getDestino() << " " << In->getOrigem1() << " " << In->getOrigem2() << endl;
                    continue;
                }
                if (In->getFuncao() == Instrucao::FUNCAO_SUB)
                {
                    output << "SUB " << In->getDestino() << " " << In->getOrigem1() << " " << In->getOrigem2() << endl;
                    continue;
                }

                if (In->getFuncao() == Instrucao::FUNCAO_MULT)
                {
                    output << "MULT " << In->getOrigem1() << " " << In->getOrigem2() << endl;
                    continue;
                }

                if (In->getFuncao() == Instrucao::FUNCAO_DIV)
                {
                    output << "DIV " << In->getOrigem1() << " " << In->getOrigem2() << endl;
                    continue;
                }
            }

            if (In->getOpcode() == Instrucao::J)
            {
                output << "J " << In->getImediato() << endl;
                continue;
            }

            if (In->getOpcode() == Instrucao::BNE)
            {
                output << "BNE " << In->getOrigem1() << " " << In->getOrigem2() << " " << In->getImediato() << endl;
                continue;
            }

            if (In->getOpcode() == Instrucao::BEQ)
            {
                output << "BEQ " << In->getOrigem1() << " " << In->getOrigem2() << " " << In->getImediato() << endl;
                continue;
            }

            if (In->getOpcode() == Instrucao::SW)
            {
                output << "SW " << In->getDestino() << " " << In->getImediato() << endl;
                continue;
            }

            if (In->getOpcode() == Instrucao::LW)
            {
                output << "LW " << In->getDestino() << " " << In->getImediato() << endl;
                continue;
            }
        }
        else
        {
            output << "D " << m->ler(i)->getValor() << endl;
        }
    }
}