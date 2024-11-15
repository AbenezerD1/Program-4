#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "movie.h"

class Classical : public Movie {
public:

private:
    std::string majorActorFirstName;
    std::string majorActorLastName;
    int month;
};

#endif