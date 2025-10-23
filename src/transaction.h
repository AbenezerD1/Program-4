#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "bst.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "customertable.h"
#include <string>

class Transaction {
public:
    Transaction(char type) : type(type) {}
    virtual ~Transaction() {}
    virtual void doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) = 0;
    char getType() const { return type; }
private:
    char type; // B, R, I, H
};

#endif