#include "classics.h"

Classics::Classics(int stock, const std::string& director, const std::string& title, const std::string& actorFirstName, const std::string& actorLastName, int month, int year) : Movie('C', stock, director, title, year), majorActorFirstName(actorFirstName), majorActorLastName(actorLastName), month(month) {}

std::string Classics::getMajorActorFirstName() {
    return majorActorFirstName;
}

std::string Classics::getMajorActorLastName() {
    return majorActorLastName;
}

int Classics::getMonth() {
    return month;
}

bool Classics::operator==(const Classics& rhs) const {
    return Movie::operator==(rhs) && majorActorFirstName == rhs.majorActorFirstName && majorActorLastName == rhs.majorActorLastName && month == rhs.month;
}

bool Classics::operator!=(const Classics& rhs) const {
    return !(*this == rhs);
}