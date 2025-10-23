#include "return.h"
#include "customer.h"

void Return::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
    // If customer exists in hashtable, add transaction to history
    Customer* customer = nullptr;
    if (!customerTable.get(customerID, customer)) {
        std::cout << "ERROR: Borrow Transaction Failed -- Customer " << customerID << " does not exist" << std::endl;
        return;
    }
    if(movie != nullptr){
        customer->addTransaction(this);
        // Increase stock if customer exists
        movie->incrementStock();
    }
}

std::ostream& operator<<(std::ostream& os, const Return& r) {
    os << "Returned " << r.getMovie()->getTitle() << " by " << r.getMovie()->getDirector();
    return os;
}