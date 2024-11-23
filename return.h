#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
    friend std::ostream& operator<<(std::ostream& os, const Return& r);
public:
    Return(int customerID, char mediaType, char movieType, Movie* movie) : Transaction('R'), customerID(customerID), mediaType(mediaType), movieType(movieType), movie(movie) {}
    void doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {}
    Movie* getMovie() const { return movie; }
private:
    int customerID;
    char mediaType; // D
    char movieType; // F, D, or C
    Movie* movie;
};

#endif