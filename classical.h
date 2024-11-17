#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "movie.h"

class Classical : public Movie {
    // C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
    friend std::ostream& operator<<(std::ostream& os, const Classical& m) {
        return os << m.getGenre() << ", " << m.getStock() << ", " << m.majorActorFirstName << " " << m.majorActorLastName << ", " << m.getTitle() << ", " << m.getDirector() << " " << m.month << " " << m.getYear();
    }
public:
    Classical(int stock, const std::string& director, const std::string& title, const std::string& actorFirstName, const std::string& actorLastName, int month, int year) : Movie('C', stock, director, title, year), majorActorFirstName(actorFirstName), majorActorLastName(actorLastName), month(month) {}
    std::string getMajorActorFirstName() { return majorActorFirstName; }
    std::string getMajorActorLastName() { return majorActorLastName; }
    int getMonth() { return month; }
private:
    std::string majorActorFirstName;
    std::string majorActorLastName;
    int month;
};

#endif