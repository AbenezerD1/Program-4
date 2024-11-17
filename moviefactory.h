#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movie.h"
#include "classical.h"
#include "drama.h"
#include "comedy.h"

class MovieFactory {
public:
    Movie* createMovie(char type) {
        switch (type) {
        case 'F':
            return new Classical();
        case 'D':
            return new Drama();
        case 'C':
            return new Comedy();
        default:
            return nullptr;
        }
    }
};

#endif