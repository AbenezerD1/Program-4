#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, std::string director, std::string title, int year) : Movie('F', stock, director, title, year) {}
    std::string getSortingKey() const {
        return getTitle() + " " + std::to_string(getYear());
    }
};

#endif