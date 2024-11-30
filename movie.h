#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
    // e.g. F, 10, Nora Ephron, Sleepless in Seattle, 1993
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        return os << m.genre << ", " << m.stock << ", " << m.director << ", " << m.title << "," << m.year;
    }
public:
    Movie(char genre, int stock, std::string director, std::string name, int year);
    virtual ~Movie();
    virtual std::string getSortingKey() const = 0;
    char getGenre() const;
    int getStock() const;
    bool decrementStock();
    void incrementStock();
    void increaseStock(int amount);
    std::string getDirector() const;
    std::string getTitle() const;
    int getYear() const;
    bool operator==(const Movie& rhs) const;
    bool operator!=(const Movie& rhs) const;
private:
    char genre; // F, D, or C
    int stock;
    std::string director;
    std::string title;
    int year;
};

#endif