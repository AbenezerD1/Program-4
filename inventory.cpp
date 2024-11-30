#include "inventory.h"

void Inventory::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
    comedyTree.print();
    dramaTree.print();
    classicsTree.print();
}