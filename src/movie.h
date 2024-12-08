#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <iomanip>

class Movie {
    // F       D       Annie Hall                         Woody Allen           1977    10   
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << std::left
           << std::setw(8)  << m.genre_
           << std::setw(8)  << m.media
           << std::setw(35) << m.title_
           << std::setw(22) << m.director_
           << std::setw(8)  << m.year_
           << std::setw(6)  << m.stock_
           << std::endl;
        return os;
    }
public:
    Movie(char genre, int stock, std::string director, std::string name, int year);
    virtual ~Movie();
    virtual std::string getSortingKey() const = 0;
    virtual std::string getMergeKey() const = 0;
    char getGenre() const { return genre_; }
    char getMedia() const { return media; }
    int getStock() const { return stock_; }
    bool decrementStock();
    void incrementStock();
    std::string getDirector() const { return director_; }
    std::string getTitle() const { return title_; }
    int getYear() const { return year_; }
    bool operator==(const Movie& rhs) const;
    bool operator!=(const Movie& rhs) const;
private:
    char genre_; // F, D, or C
    char media = 'D'; // D
    int stock_;
    std::string director_;
    std::string title_;
    int year_;
};

#endif