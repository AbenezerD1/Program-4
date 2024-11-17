#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "movie.h"

class Classical : public Movie {
    // C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        return os << m.genre << ", " << m.stock << ", " << m.director << ", " << m.title << "," << m.year;
    }
public:

private:
    std::string majorActorFirstName;
    std::string majorActorLastName;
    int month;
};

#endif