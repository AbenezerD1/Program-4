#include "hashtable.h"

HashTable::HashTable(int size) : capacity(size) {
    table.resize(capacity);
}

void HashTable::insert(const std::string& key, int value) {
    int index = hash(key);
    for (auto& node : table[index]) {
        if (node.key == key) {
            node.value = value; // Update value if key exists
            return;
        }
    }
    table[index].emplace_back(key, value); // Insert new key-value pair
}

bool HashTable::get(const std::string& key, int& value) const {
    int index = hash(key);
    for (const auto& node : table[index]) {
        if (node.key == key) {
            value = node.value;
            return true;
        }
    }
    return false; // Key not found
}

void HashTable::remove(const std::string& key) {
    int index = hash(key);
    table[index].remove_if([&key](const Node& node) { return node.key == key; });
}

void HashTable::print() {
    for (int i = 0; i < capacity; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& node : table[i]) {
            std::cout << "[" << node.key << ": " << node.value << "] ";
        }
        std::cout << "\n";
    }
}

int HashTable::hash(const std::string& key) const {
    int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31 + c) % capacity;
    }
    return hashValue;
}
