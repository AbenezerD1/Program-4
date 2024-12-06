#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "bst.h"
#include <string>

class TransactionFactory {
public:
    static Transaction* createTransaction(std::string& line, BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
        std::istringstream stream(line);
        // Trim leading whitespace
        stream >> std::ws;
        if (stream.eof()) {
            return nullptr;
        }
        char type;
        stream >> type;
        if (type != 'B' && type != 'R' && type != 'I' && type != 'H') {
            std::cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << std::endl;
            return nullptr;
        }
        if (type == 'I') {
            return new Inventory();
        }
        int customerID;
        stream >> customerID;
        if (type == 'H') {    
            return new History(customerID);
        }
        // If type is B or R
        char mediaType;
        char movieType;
        stream >> mediaType >> movieType;
        // If media type is not DVD
        if (mediaType != 'D') {
            std::cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << std::endl;
            return nullptr;
        }
        // If movie type is not Comedy, Drama, or Classics
        if (movieType != 'F' && movieType != 'D' && movieType != 'C') {
            std::cout << "ERROR: " << movieType << " Invalid Genre. Try Again." << std::endl;
            return nullptr;
        }
        Movie* movie = nullptr;
        // Parsing comedy movie
        if (movieType == 'F') {
            std::string title;
            int year;
            stream >> std::ws;
            std::getline(stream, title, ',');
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            stream >> year;
            if (!comedyTree.get(Comedy::generateKey(title, year), movie)) {
                std::cout << "ERROR: Comedy Movie Does Not Exist In The Inventory. Try Again." << std::endl;
                return nullptr;
            }
        }
        // Parsing drama movie
        else if (movieType == 'D') {
            std::string director;
            std::string title;
            stream >> std::ws;
            std::getline(stream, director, ',');
            director.erase(director.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            std::getline(stream, title);
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            title.erase(title.find_last_of(","));
            if (!dramaTree.get(Drama::generateKey(director, title), movie)) {
                std::cout << "ERROR: Drama Movie Does Not Exist In The Inventory. Try Again." << std::endl;
                return nullptr;
            }
        }
        // Parsing classics movie
        else {
            Classics* classics = nullptr;
            int month;
            int year;
            std::string actorFirstName;
            std::string actorLastName;
            stream >> month >> year >> actorFirstName >> actorLastName;
            if (!classicsTree.get(Classics::generateKey(year, month, actorFirstName, actorLastName), movie)) {
                std::cout << "ERROR: Classics Movie Does Not Exist In The Inventory. Try Again." << std::endl;
                return nullptr;
            }
        }
        if (!movie) {
            std::cout << "ERROR: Movie Does Not Exist In The Inventory. Try Again." << std::endl;
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