#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"

class TransactionFactory {
public:
    Transaction* createTransaction(char type) {
        switch (type) {
        case 'B':
            return new Borrow();
        case 'R':
            return new Return();
        case 'I':
            return new Inventory();
        case 'H':
            return new History();
        default:
            return nullptr;
        }
    }
};

#endif