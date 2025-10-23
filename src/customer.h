#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "transaction.h"

class Customer {
public:
    Customer(int id, std::string lastName, std::string firstName) 
        : id_(id), lastName(lastName), firstName(firstName) { id_ < 0 ? id_ = 0: id_; }
    ~Customer() {
        for (Transaction* transaction : transactionHistory) {
            transaction = nullptr; // Prevent double delete
        }
        transactionHistory.clear();
    }
    int getID() const { return id_; }
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    const std::vector<Transaction*>& getTransactionHistory() const { return transactionHistory; }
    void addTransaction(Transaction* transaction) { transactionHistory.push_back(transaction); }
private:
    int id_;
    std::string lastName;
    std::string firstName;
    std::vector<Transaction*> transactionHistory;
};

#endif