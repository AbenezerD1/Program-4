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
        stream >> customerID >> mediaType >> movieType;
        // Parse customer ID
        if (!customerTable.get(customerID, nullptr)) {
            std::cout << "ERROR: " << customerID << " Customer Does Not Exist. Try Again." << std::endl;
            return nullptr;
        }
        // If media type is not DVD
        if (mediaType != 'D') {
            std::cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << std::endl;
            return nullptr;
        }
        // If movie type is not Comedy, Drama, or Classics
        if (movieType != 'F' && movieType != 'D' && movieType != 'C') {
            std::cout << "ERROR: " << movieType << " Invalid Movie Type. Try Again." << std::endl;
            return nullptr;
        }
        Movie* movie = nullptr;
        // Parsing comedy movie
        if (movieType == 'F') {
            std::string title;
            int year;
            std::getline(stream, title, ',');
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            stream >> year;
            std::string key = title + std::to_string(year);
            if (!comedyTree.get(key, movie)) {
                std::cout << "ERROR: Movie Does Not Exist In The Inventory. Try Again." << std::endl;
                return nullptr;
            }
        }
        // Parsing drama movie
        else if (movieType == 'D') {
            std::string director;
            std::string title;
            std::getline(stream, title, ',');
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            std::getline(stream, title);
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            std::string key = director + " " + title;
            if (!dramaTree.get(key, movie)) {
                std::cout << "ERROR: Movie Does Not Exist In The Inventory. Try Again." << std::endl;
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
            std::string key = actorFirstName + " " + actorLastName + " " + std::to_string(month) + " " + std::to_string(year);
            if (!classicsTree.get(key, movie)) {
                std::cout << "ERROR: Movie Does Not Exist In The Inventory. Try Again." << std::endl;
                return nullptr;
            }
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