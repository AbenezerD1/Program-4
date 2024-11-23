#include "history.h"

// Prints customer's transaction history
void History::doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {
    Customer* customer = nullptr;
    if (!customerTable.get(customerID, customer)) {
        std::cout << "ERROR: History Transaction Failed -- Customer " << customerID << " does not exist" << std::endl;
    }
    std::cout << "History for " << customer->getFirstName() << " " << customer->getLastName() << ":" << std::endl;
    for (Transaction* transaction : customer->getTransactionHistory()) {
        std::cout << transaction << std::endl;
    }
    std::cout << std::endl;
}