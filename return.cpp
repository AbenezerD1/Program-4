#include "return.h"

void Return::doTransaction(MovieTable& movieTable, CustomerTable& customerTable) {
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
    // Increase stock if movie and customer exists
    movie->increaseStock();
}

std::ostream& operator<<(std::ostream& os, const Return& r) {
    os << "Returned " << r.getMovie()->getTitle() << " by " << r.getMovie()->getDirector() << std::endl;
    return os;
}