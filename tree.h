//
// Created by chip on 18/09/18.
//

#ifndef BINARY_TREE_NCHIPANAUTEC_TREE_H
#define BINARY_TREE_NCHIPANAUTEC_TREE_H

#include "iterator.h"
#include <iostream>
using namespace std;

class Tree{
    stack<Node*> nodos;
    Node* raiz;
public:
    Tree():raiz(nullptr){}

    Node* get_root(){
        return raiz;
    }

    void print_in_order(Node* root){
        if(root){
            print_in_order(root->left);
            cout << root -> data << " ";
            print_in_order(root->right);
        }
        else{return;}
    }

    void print_in_preorder(Node* root){
        if(root){
            cout << root -> data << " ";
            print_in_order(root->left);
            print_in_order(root->right);
        }
        else{return;}
    }

    void print_in_postorder(Node* root){
        if(root){
            print_in_order(root->left);
            print_in_order(root->right);
            cout << root -> data << " ";
        }
        else{return;}
    }

    void buildStack(Node* nodo){
        if(nodo){
            buildStack(nodo->right);
            nodos.push(nodo);
            buildStack(nodo->left);
        }
        else {return;}
    }


    void insert(int data, Node* root){
        if(!raiz){
            raiz = new Node {data, nullptr, nullptr};
        }
        else{
            if(root->data == data){return;}
            Node* nodo = root;
            if(data < nodo -> data){
                if(nodo -> left){
                    nodo = nodo -> left;
                    insert(data,nodo);
                }
                else{
                    nodo -> left = new Node{data, nullptr, nullptr};
                }
            }
            else{
                if(nodo -> right){
                    nodo = nodo -> right;
                    insert(data,nodo);
                }
                else{
                    nodo -> right = new Node{data, nullptr, nullptr};
                }
            }
        }
    }

    Node* minNodo(Node* nodo){
        if(!nodo){return nullptr;}
        while(!nodo -> left){nodo = nodo -> left;}
    }
    Node* maxNodo(Node* nodo){
        if(!nodo){return nullptr;}
        while(!nodo -> right){nodo = nodo -> right;}
    }

    void remove(int data, Node* nodo){
        if(!raiz){
            cout << "Lista Vacía";
            return;
        }
        else if (data < nodo -> data){remove(data,nodo -> left);}
        else if (data > nodo -> data){remove(data,nodo -> right);}
        else{
            if(!nodo -> left && !nodo -> right){
                delete nodo;
                nodo = nullptr;
            }
            else if(!nodo -> left){
                Node* temp = nodo;
                nodo = nodo -> left;
                delete temp;
            }
            else if(!nodo -> right){
                Node* temp = nodo;
                nodo = nodo -> right;
                delete temp;
            }
            else{
                Node* temp = minNodo(nodo -> right);
                nodo -> data = temp -> data;
                remove(data,nodo -> right);
            }
        }
    }

    int weight(Node* nodo) {
        if (nodo) {
            return 1 + weight(nodo->left) + weight(nodo->right);
        } else {
            return 0;
        }
    }

    Iterator begin(){
        return Iterator(minNodo(raiz));
    }

    Iterator end(){
        return Iterator(maxNodo(raiz));
    }

    stack<Node*> getStack(){
        return nodos;
    }

};

/* insert
 * remove
 * weight
 * iterator
 * print
 * order
 * preorder
 */

#endif //BINARY_TREE_NCHIPANAUTEC_TREE_H
