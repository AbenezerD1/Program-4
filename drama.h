#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
    Drama(int stock, std::string director, std::string title, int year) : Movie('D', stock, director, title, year) {}
};

#endif