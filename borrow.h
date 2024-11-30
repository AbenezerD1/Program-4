#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
    friend std::ostream& operator<<(std::ostream& os, const Borrow& b);
public:
    Borrow(int customerID, char mediaType, char movieType, Movie* movie) : Transaction('B'), customerID(customerID), mediaType(mediaType), movieType(movieType), movie(movie) {}
    void doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable);
    Movie* getMovie() const { return movie; }
private:
    int customerID;
    char mediaType; // D
    char movieType; // F, D, or C
    Movie* movie;
};

#endif