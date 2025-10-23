#include "movie.h"

#include <regex>

Movie::Movie(char genre, int stock, std::string director, std::string name, int year) : genre_(genre), stock_(stock), director_(director), title_(name), year_(year) {
    if (stock_ < 0) stock_ = 0;
    if (year_ < 0) year_ = 0;
    for (int i = 0; i < std::max(director_.length(),title_.length()); i++) {
        if (director_.length() >= i && std::isdigit(director_[i])) {
            director_ = "";
        }
        if (title_.length() >= i && std::isdigit(title_[i])) {
            title_ = "";
        }
    }
}

Movie::~Movie() {}

// Returns false if cannot decrease stock
bool Movie::decrementStock() { 
    if (stock_ == 0) {
        return false;
    }
    stock_--;
    return true;
}

void Movie::incrementStock() {
    stock_++;
}

bool Movie::operator==(const Movie& rhs) const {
    return genre_ == rhs.genre_ && stock_ == rhs.stock_ && director_ == rhs.director_ && title_ == rhs.title_ && year_ == rhs.year_;
}

bool Movie::operator!=(const Movie& rhs) const {
    return !(*this == rhs);
}