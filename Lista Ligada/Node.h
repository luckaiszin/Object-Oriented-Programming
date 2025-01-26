#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
public:
    int chave;
    Node *proximo;
    Node();
    Node(int chave);
    ~Node();
};

#endif