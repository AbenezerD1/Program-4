#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "movietable.h"
#include <string>

class TransactionFactory {
public:
    static Transaction* createTransaction(std::string& line, MovieTable& movieTable, CustomerTable& customerTable) {
        std::istringstream stream(line);
        char type;
        stream >> type;
        if (type != 'B' && type != 'R' && type != 'I' && type != 'H') {
            std::cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << std::endl;
            return nullptr;
        }
        if (type == 'I') {
            return new Inventory();
        }
        if (type == 'H') {
            int customerID;
            return new History(customerID);
        }
        // If type is B or R
        int customerID;
        char mediaType;
        char movieType;
        Movie* movie;
        stream >> customerID >> mediaType >> movieType;
        // Parse movie from variable string
        if (!customerTable.get(customerID, nullptr)) {
            std::cout << "ERROR: " << customerID << " Customer Does Not Exist. Try Again." << endl;
            return nullptr;
        }
        // If media type is not DVD
        if (mediaType != 'D') {
            std::cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
            return nullptr;
        }
        // If movie type is not Comedy, Drama, or Classics
        if (movieType != 'F' && movieType != 'D' && movieType != 'C') {
            std::cout << "ERROR: " << movieType << " Invalid Movie Type. Try Again." << endl;
            return nullptr;
        }
        // Parse movie from variable string
        if (!movieTable.get(movie->getTitle(), movie)) {
            std::cout << "ERROR: Movie Does Not Exist In The Inventory. Try Again." << endl;
            return nullptr;
        }
        switch (type) {
        case 'B':
            return new Borrow(customerID, mediaType, movieType, movie);
        case 'R':
            return new Return(customerID, mediaType, movieType, movie);
        default:
            return nullptr;
        }
    }
};

#endif