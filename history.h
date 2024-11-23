#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class History : public Transaction {
public:
    History(int customerID) : Transaction('H') {}
    void doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {}
private:
    int customerID;
};

#endif