#include "history.h"
#include "customer.h"

// Prints customer's transaction history
void History::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
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