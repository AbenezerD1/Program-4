#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class History : public Transaction {
public:
    History(int customerID) : Transaction('H') {}
    void doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable);
private:
    int customerID;
};

#endif