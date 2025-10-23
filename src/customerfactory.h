#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "customer.h"
#include <string>
#include <sstream>

class CustomerFactory {
public:
    static Customer* createCustomer(std::string& line) {
        std::istringstream stream(line);
        // Trim leading whitespace
        stream >> std::ws;
        if (stream.eof()) {
            return nullptr;
        }
        int id;
		std::string lastName;
		std::string firstName;
		stream >> id >> lastName >> firstName;
		return new Customer(id, lastName, firstName);
    }
};

#endif