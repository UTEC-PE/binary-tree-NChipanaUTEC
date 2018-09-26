//
// Created by chip on 18/09/18.
//

#include "tree.h"

int main(){
    Tree arbol;
    for(int i = 0; i < 30; i++){
     arbol.add_value(i*5,arbol.get_root());
    }
    arbol.print_node(arbol.get_root());
    return 0;
};