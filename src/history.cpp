#include "history.h"
#include "customer.h"
#include "borrow.h"
#include "return.h"

// Prints customer's transaction history
void History::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
    Customer* customer = nullptr;
    if (!customerTable.get(customerID, customer)) {
        std::cout << "ERROR: History Transaction Failed -- Customer " << customerID << " does not exist" << std::endl;
    }
    std::cout << "History for " << customer->getFirstName() << " " << customer->getLastName() << ":" << std::endl;
    // Iterate from newest to oldest
    for (auto it = customer->getTransactionHistory().rbegin(); it != customer->getTransactionHistory().rend(); ++it) {
        Transaction* transaction = *it;
        if (transaction->getType() == 'B') {
            std::cout << *static_cast<Borrow*>(transaction) << std::endl;
        } else if (transaction->getType() == 'R') {
            std::cout << *static_cast<Return*>(transaction) << std::endl;
        }
    }
    std::cout << std::endl;
}