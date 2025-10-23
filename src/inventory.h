#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

class Inventory : public Transaction {
public:
    Inventory() : Transaction('I') {}
    void doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable);
};

#endif