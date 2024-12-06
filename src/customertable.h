#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

// #include "customer.h"
#include <iostream>
class Customer;

class CustomerTable {
public:
    CustomerTable(int cap);
    ~CustomerTable();
    bool insert(Customer* customer);
    bool get(int customerID, Customer*& customer);
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

private:
    Customer** table; // Array of Customer pointers
    int capacity;
    int size;
    int hash(int customerID) const;
    int probe(int index) const; // Linear probing logic
};

#endif