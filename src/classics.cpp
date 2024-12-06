#include "classics.h"

Classics::Classics(int stock, const std::string& director, const std::string& title, const std::string& actorFirstName, const std::string& actorLastName, int month, int year) : Movie('C', stock, director, title, year), majorActorFirstName(actorFirstName), majorActorLastName(actorLastName), month(month) {}

std::string Classics::getSortingKey() const {
    return generateKey(getYear(), getMonth(), majorActorFirstName, majorActorLastName);
}

std::string Classics::generateKey(int year, int month, std::string majorActorFirstName, std::string majorActorLastName) {
    return std::to_string(year) + std::to_string(month) + " " + majorActorFirstName + " " + majorActorLastName;
}

std::string Classics::getMergeKey() const {
    return getDirector() + "_" + getTitle() + "_" + std::to_string(month) + "_" + std::to_string(getYear());
}

bool Classics::operator==(const Classics& rhs) const {
    return Movie::operator==(rhs) && majorActorFirstName == rhs.majorActorFirstName && majorActorLastName == rhs.majorActorLastName && month == rhs.month;
}

bool Classics::operator!=(const Classics& rhs) const {
    return !(*this == rhs);
}