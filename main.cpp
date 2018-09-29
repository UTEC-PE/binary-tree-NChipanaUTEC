//
// Created by chip on 18/09/18.
//

#include "tree.h"
#include "iterator.h"

int main(){
    Tree arbol;
    arbol.insert(4,arbol.get_root());
    arbol.insert(2,arbol.get_root());
    arbol.insert(3,arbol.get_root());
    arbol.insert(6,arbol.get_root());
    arbol.insert(5,arbol.get_root());
    arbol.insert(-2,arbol.get_root());
    arbol.buildStack(arbol.get_root());

    Iterator it;
    it.setStack(arbol.getStack());


    for(it = it.begin(); it.pile.size()>1; ++it){
        cout << *it << " ";
    }
    cout << *it;


//    arbol.print_in_order(arbol.get_root());
//    cout << endl;

    /*
    arbol.print_in_preorder(arbol.get_root());
    cout << endl;
    arbol.print_in_postorder(arbol.get_root());
    cout << endl;
    */
//     cout << arbol.weight(arbol.get_root());
    return 0;
};