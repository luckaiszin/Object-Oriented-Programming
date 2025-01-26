#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{
public:

    Node * Inicio;
    List();
    ~List();
    void search(int k);
    void insert(Node x);
    void remove(Node x);
};

#endif