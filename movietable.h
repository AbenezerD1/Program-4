#ifndef MOVIETABLE_H
#define MOVIETABLE_H 

#include "movie.h"
#include <iostream>
#include <string>

class MovieTable {
public:
    MovieTable(int cap);
    ~MovieTable();
    bool insert(Movie* movie);
    bool remove(const std::string& key);
    bool MovieTable::get(const std::string& key, Movie* movie);
    void print() const;
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
private:
    Movie** table; // Array of Movie pointers
    int capacity;
    int size;
    int hash(const std::string& key) const;
    int probe(int index) const; // Linear probing logic
};

#endif