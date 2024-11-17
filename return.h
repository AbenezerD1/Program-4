#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"
#include "movie.h"
#include "hashtable.h"

class Return : public Transaction {
public:
    void doTransaction(HashTable& ht);
    void setData(std::string data);
    void display() const;
private:
    int customerID;
    Movie movie;
};

#endif