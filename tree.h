//
// Created by chip on 18/09/18.
//

#ifndef BINARY_TREE_NCHIPANAUTEC_TREE_H
#define BINARY_TREE_NCHIPANAUTEC_TREE_H

#include "node.h"
#include <iostream>
using namespace std;

class Tree{
    Node* raiz;
public:
    Tree():raiz(nullptr){}

    Node* get_root(){
        return raiz;
    }


    void print_node(Node* root){
        if(root){
            print_node(root->left);
            cout << root -> data << " ";
            print_node(root->right);
        }
        else{
            return;
        }
    }

    void add_value(int data, Node* root){
        if(!raiz){
            raiz = new Node {data, nullptr, nullptr};
        }
        else{
            if(root->data == data){return;}
            Node* nodo = root;
            if(data < nodo -> data){
                if(nodo -> left){
                    nodo = nodo -> left;
                    add_value(data,nodo);
                }
                else{
                    nodo -> left = new Node{data, nullptr, nullptr};
                }
            }
            else{
                if(nodo -> right){
                    nodo = nodo -> right;
                    add_value(data,nodo);
                }
                else{
                    nodo -> right = new Node{data, nullptr, nullptr};
                }
            }
        }
    }

};


#endif //BINARY_TREE_NCHIPANAUTEC_TREE_H
