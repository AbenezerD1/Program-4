#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
    Drama(int stock, std::string director, std::string title, int year) : Movie('D', stock, director, title, year) {}
    std::string getSortingKey() const {
        return generateKey(getDirector(), getTitle());
    }
    static std::string generateKey(std::string director, std::string title) {
        return director + " " + title;
    }
    std::string getMergeKey() const { return ""; }
};

#endif