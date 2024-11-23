#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
public:
    Customer(int id, std::string lastName, std::string firstName) : id(id), lastName(lastName), firstName(firstName) {}
    int getID() const { return id; }
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::vector<Transaction*> getTransactionHistory() const { return transactionHistory; }
    void addTransaction(Transaction* transaction) { transactionHistory.push_back(transaction); }
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::vector<Transaction*> transactionHistory;
};

#endif