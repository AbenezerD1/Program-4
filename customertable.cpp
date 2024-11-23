#include "customertable.h"

CustomerTable::CustomerTable(int cap) : capacity(cap), size(0) {
    table = new Customer*[capacity];
    // Initialize all slots to nullptr
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
}

CustomerTable::~CustomerTable() {
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
    delete[] table;
}

bool CustomerTable::insert(Customer* customer) {
    // If table is full
    if (size >= capacity) {
        return false;
    }

    int customerID = customer->getID();
    int index = hash(customerID);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        if (table[newIndex] == nullptr) {
            table[newIndex] = customer;
            size++;
            return true;
        }
        // Avoid duplicate customer IDs
        if (table[newIndex]->getID() == customerID) {
            return false;
        }
    }
    // Should not reach here
    return false;
}

bool CustomerTable::remove(int customerID) {
    int index = hash(customerID);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        // Customer not found
        if (table[newIndex] == nullptr) {
            return false;
        }
        if (table[newIndex]->getID() == customerID) {
            delete table[newIndex];
            table[newIndex] = nullptr;
            size--;
            return true;
        }
    }
    return false;
}

bool CustomerTable::get(int customerID, Customer* customer) {
    int index = hash(customerID);

    for (int i = 0; i < capacity; ++i) {
        int newIndex = probe(index + i);
        // Customer not found
        if (table[newIndex] == nullptr) {
            customer = nullptr;
            return false;
        }
        if (table[newIndex]->getID() == customerID) {
            customer = table[newIndex];
            return true;
        }
    }
    customer = nullptr;
    return false;
}

void CustomerTable::print() const {
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            std::cout << "Bucket " << i << ": [ID: " << table[i]->getID()
                      << ", Name: " << table[i]->getFirstName() << " "
                      << table[i]->getLastName() << "]\n";
        } else {
            std::cout << "Bucket " << i << ": [empty]\n";
        }
    }
}

int CustomerTable::hash(int customerID) const {
    // Sum of digits
    int sumOfDigits = 0;
    int tempID = customerID;
    while (tempID > 0) {
        sumOfDigits += tempID % 10;
        tempID /= 10;
    }

    // Multiply sum by a prime number and mod with capacity
    return (sumOfDigits * 31 + customerID * 7) % capacity;
}

int CustomerTable::probe(int index) const {
    return index % capacity;
}