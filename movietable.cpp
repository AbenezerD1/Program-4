#include "movietable.h"

MovieTable::MovieTable(int cap) : capacity(cap), size(0) {
    table = new Movie*[capacity];
    // Initialize all slots to nullptr
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
}

MovieTable::~MovieTable() {
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
    delete[] table;
}

bool MovieTable::insert(Movie* movie) {
    // If table is full
    if (size >= capacity) {
        return false;
    }

    std::string key = movie->getTitle();
    int index = hash(key);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        if (table[newIndex] == nullptr) {
            table[newIndex] = movie;
            size++;
            return true;
        }
        // Avoid duplicate keys
        if (table[newIndex]->getTitle() == key) {
            return false;
        }
    }
    // Should not reach here
    return false;
}

bool MovieTable::remove(const std::string& key) {
    int index = hash(key);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        // Key not found
        if (table[newIndex] == nullptr) {
            return false;
        }
        if (table[newIndex]->getTitle() == key) {
            delete table[newIndex];
            table[newIndex] = nullptr;
            size--;
            return true;
        }
    }
    return false;
}

bool MovieTable::get(const std::string& key, Movie* movie) {
    int index = hash(key);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        // Key not found
        if (table[newIndex] == nullptr) {
            movie = nullptr;
            return false;
        }
        if (table[newIndex]->getTitle() == key) {
            movie = table[newIndex];
            return true;
        }
    }
    movie = nullptr;
    return false;
}

void MovieTable::print() const {
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            std::cout << "Bucket " << i << ": [" << table[i]->getTitle() << "]\n";
        } else {
            std::cout << "Bucket " << i << ": [empty]\n";
        }
    }
}

int MovieTable::hash(const std::string& key) const {
    int hash = 0;
    for (char c : key) {
        hash = hash * 31 + c;
    }
    return hash % capacity;
}

int MovieTable::probe(int index) const {
    return index % capacity;
}