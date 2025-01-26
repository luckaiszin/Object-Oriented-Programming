#include "Node.h"

Node::Node()
{
    this->proximo = NULL;
}

Node::Node(int chave)
{
    this->chave = chave;
    this->proximo = NULL;
}

Node::~Node()
{
}