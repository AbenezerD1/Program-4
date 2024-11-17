#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        return os << m.genre << ", " << m.stock << ", " << m.director << ", " << m.title << "," << m.year;
    }
public:
    Movie(char genre, int stock, std::string director, std::string name, int year) : genre(genre), stock(stock), director(director), title(name), year(year) {}
    char getGenre() const { return genre; }
    int getStock() const { return stock; }
    bool decreaseStock() { return --stock; }
    bool increaseStock() { return ++stock; }
    std::string getDirector() const { return director; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
private:
    char genre; // either F, D, or C
    int stock;
    std::string director;
    std::string title;
    int year;
    int runningTime;
    int stock;
    double price;    
};

#endif