#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "movie.h"

class Classics : public Movie {
    // C       D       Casablanca                         Michael Curtiz        8       1942    20
    friend std::ostream& operator<<(std::ostream& os, const Classics& m) {
        os << std::left
           << std::setw(8)  << m.getGenre()
           << std::setw(8)  << m.getMedia()
           << std::setw(35) << m.getTitle()
           << std::setw(22) << m.getDirector()
           << std::setw(8)  << m.month
           << std::setw(8)  << m.getYear();
        return os;
    }
public:
    Classics(int stock, const std::string& director, const std::string& title, const std::string& actorFirstName, const std::string& actorLastName, int month, int year);
    std::string getSortingKey() const;
    static std::string generateKey(int year, int month, std::string majorActorFirstName, std::string majorActorLastName);
    std::string getMergeKey() const;
    std::string getMajorActorFirstName() const { return majorActorFirstName; }
    std::string getMajorActorLastName() const { return majorActorLastName; }
    int getMonth() const { return month; }
    virtual bool operator==(const Classics& rhs) const;
    virtual bool operator!=(const Classics& rhs) const;
private:
    std::string majorActorFirstName;
    std::string majorActorLastName;
    int month;
};

#endif