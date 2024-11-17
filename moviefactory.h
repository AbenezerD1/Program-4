#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movie.h"
#include "classical.h"
#include "drama.h"
#include "comedy.h"
#include <string>

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
            return nullptr;
        }
        stream.ignore(2); // Ignore comma and space
        stream >> stock;
        stream.ignore(2); // Ignore comma and space
        // Special parsing for Classical movies
        if (type == 'C') {
            std::string actorFirstName, actorLastName;
            int month;
            std::getline(stream, director, ',');
            director.erase(director.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            stream >> actorFirstName >> actorLastName;
            stream.ignore(1); // Ignore space
            std::getline(stream, title, ',');
            title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
            stream.ignore(1); // Ignore space
            stream >> month >> year;
            return new Classical(stock, director, title, actorFirstName, actorLastName, month, year);
        }
        std::getline(stream, director, ',');
        director.erase(director.find_last_not_of(" ") + 1); // Trim trailing spaces
        stream.ignore(1); // Ignore space
        std::getline(stream, title, ',');
        title.erase(title.find_last_not_of(" ") + 1); // Trim trailing spaces
        stream.ignore(1); // Ignore space
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