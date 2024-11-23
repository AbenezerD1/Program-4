#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "movietable.h"
#include "customertable.h"
#include <string>

class Transaction {
public:
    Transaction(char type) : type(type) {}
    virtual ~Transaction() {}
    virtual void doTransaction(MovieTable& movieTable, CustomerTable& customerTable) = 0;
    char getType() const { return type; }
private:
    char type; // B, R, I, H
};

#endif