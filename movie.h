#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <iomanip>

class Movie {
    // F       D       Annie Hall                         Woody Allen           1977    10   
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << std::left
           << std::setw(8)  << m.genre
           << std::setw(8)  << m.media
           << std::setw(35) << m.title
           << std::setw(22) << m.director
           << std::setw(8)  << m.year
           << std::setw(6)  << m.stock
           << std::endl;
        return os;
    }
public:
    Movie(char genre, int stock, std::string director, std::string name, int year);
    virtual ~Movie();
    virtual std::string getSortingKey() const = 0;
    virtual std::string getMergeKey() const = 0;
    char getGenre() const { return genre; }
    char getMedia() const { return media; }
    int getStock() const { return stock; }
    bool decrementStock();
    void incrementStock();
    std::string getDirector() const { return director; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    bool operator==(const Movie& rhs) const;
    bool operator!=(const Movie& rhs) const;
private:
    char genre; // F, D, or C
    char media = 'D'; // D
    int stock;
    std::string director;
    std::string title;
    int year;
};

#endif