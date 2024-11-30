#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "classics.h"
#include "drama.h"
#include "comedy.h"
#include <string>
#include <sstream>

class MovieFactory {
public:
    static Movie* createMovie(std::string& line) {
        std::istringstream stream(line);
        char type;
        int stock;
        std::string director;
        std::string title;
        int year;
        // Parse the input
        stream >> type;
        if (type != 'F' && type != 'D' && type != 'C') {
            std::cout << "ERROR: " << type << " Invalid Genre. Try Again." << std::endl;
            return nullptr;
        }
        stream.ignore(2); // Ignore comma and space
        stream >> stock;
        stream.ignore(2);
        // Special parsing for Classics movies
        if (type == 'C') {
            std::string actorFirstName, actorLastName;
            int month;
            std::getline(stream, director, ',');
            director.erase(director.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            std::getline(stream, title, ',');
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1);
            stream >> actorFirstName >> actorLastName;
            stream.ignore(1);
            stream >> month >> year;
            return new Classics(stock, director, title, actorFirstName, actorLastName, month, year);
        }
        std::getline(stream, director, ',');
        director.erase(director.find_last_not_of(" ") + 1); // Trim trailing spaces
        stream.ignore(1); // Ignore space
        std::getline(stream, title, ',');
        title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
        stream.ignore(1);
        stream >> year;
        // Create movie
        switch (type) {
        case 'D':
            return new Drama(stock, director, title, year);
        case 'F':
            return new Comedy(stock, director, title, year);
        default:
            return nullptr;
        }
    }
};

#endif