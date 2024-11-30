#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "movie.h"

class Classics : public Movie {
    // e.g. C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
    friend std::ostream& operator<<(std::ostream& os, const Classics& m) {
        return os << m.getGenre() << ", " << m.getStock() << ", " << m.majorActorFirstName << " " << m.majorActorLastName << ", " << m.getTitle() << ", " << m.getDirector() << " " << m.month << " " << m.getYear();
    }
public:
    Classics(int stock, const std::string& director, const std::string& title, const std::string& actorFirstName, const std::string& actorLastName, int month, int year);
    std::string getSortingKey() const;
    std::string getMergeKey() const;
    std::string getMajorActorFirstName();
    std::string getMajorActorLastName();
    int getMonth();
    virtual bool operator==(const Classics& rhs) const;
    virtual bool operator!=(const Classics& rhs) const;
private:
    std::string majorActorFirstName;
    std::string majorActorLastName;
    int month;
};

#endif