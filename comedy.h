#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, std::string director, std::string title, int year) : Movie('D', stock, director, title, year) {}
};

#endif