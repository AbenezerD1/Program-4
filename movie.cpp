#include "movie.h"

Movie::Movie(char genre, int stock, std::string director, std::string name, int year) : genre(genre), stock(stock), director(director), title(name), year(year) {}

Movie::~Movie() {}

bool Movie::decrementStock() { 
    if (stock == 0) { 
        return false;
    }
    stock--;
    return true;
}

void Movie::incrementStock() {
    stock++;
}

void Movie::increaseStock(int amount) {
    stock += amount;
}

bool Movie::operator==(const Movie& rhs) const {
    return genre == rhs.genre && stock == rhs.stock && director == rhs.director && title == rhs.title && year == rhs.year;
}

bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}