#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        return os << m.genre << ", " << m.stock << ", " << m.director << ", " << m.title << "," << m.year;
    }
public:

private:
    char genre; // either F, D, or C
    int stock;
    std::string director;
    std::string title;
    std::string year;
    int runningTime;
    int stock;
    double price;    
};

#endif