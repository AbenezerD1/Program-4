#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

class HashTable {
public:
    HashTable(int size);
    void insert(const std::string& key, int value);
    bool get(const std::string& key, int& value) const;
    void remove(const std::string& key);
    void print();
private:
    struct Node {
        std::string key;
        int value;
        Node(std::string k, int v) : key(k), value(v) {}
    };

    std::vector<std::list<Node>> table;
    int capacity;

    // Hash function to map keys to indices
    int hash(const std::string& key) const;
};

#endif