#include "borrow.h"

void Borrow::doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {
    // If movie exists in hashtable
    if (!movieTable.get(movie->getTitle(), movie)) {
        std::cout << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << std::endl;
        return;
    }
    // If customer exists in hashtable, add transaction to history
    Customer* customer = nullptr;
    if (!customerTable.get(customerID, customer)) {
        std::cout << "ERROR: Borrow Transaction Failed -- Customer " << customerID << " does not exist" << std::endl;
    }
    customer->addTransaction(this);
    // Decrease stock if movie and customer exists
    if (!movie->decreaseStock()) {
        std::cout << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << std::endl;
        return;
    }
}

std::ostream& operator<<(std::ostream& os, const Borrow& b) {
    os << "Borrowed " << b.getMovie()->getTitle() << " by " << b.getMovie()->getDirector() << std::endl;
    return os;
}
