#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

class Inventory : public Transaction {
public:
    Inventory() : Transaction('I') {}
    void doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {}
};

#endif