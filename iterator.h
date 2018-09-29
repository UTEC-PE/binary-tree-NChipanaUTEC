//
// Created by chip on 18/09/18.
//

#ifndef BINARY_TREE_NCHIPANAUTEC_ITERATOR_H
#define BINARY_TREE_NCHIPANAUTEC_ITERATOR_H

#include "node.h"
#include <iostream>
#include <stack>
using namespace std;

class Iterator{
public:
    stack <Node*> pile;
    Node* current;

    Iterator(){
        current = nullptr;
    }

    Iterator (Node* nodo){
        this -> current = nodo;
    }

    Iterator operator++(){
        pile.pop();
        current = pile.top();
    }

    bool operator!=(Iterator other){
        return current -> data != other.current -> data;
    }

    int operator*(){
        return current -> data;
    }

    Iterator begin(){
        this -> current = pile.top();
        return* this;
    }

    Iterator setStack(stack<Node*> nodos){
        pile = nodos;
        return* this;
    }

};


#endif //BINARY_TREE_NCHIPANAUTEC_ITERATOR_H
