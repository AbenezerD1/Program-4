#include "borrow.h"
#include "customer.h"

void Borrow::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
    // If customer exists in hashtable, add transaction to history
    Customer* customer = nullptr;
    if (!customerTable.get(customerID, customer)) {
        std::cout << "ERROR: Borrow Transaction Failed -- Customer " << customerID << " does not exist" << std::endl;
        return;
    }
    customer->addTransaction(this);
    // Decrease stock if customer exists
    // If movie stock is 0 and movie is classics
    if (!movie->decrementStock() && movie->getGenre() == 'C') {
        // Check if title matches existing movie, but different director
        Movie* otherMovie = nullptr;
        if (classicsTree.inorderSearch(movie->getMergeKey(), otherMovie)) {
            otherMovie->decrementStock();
        }
        std::cout << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << std::endl;
        return;
    }
}

std::ostream& operator<<(std::ostream& os, const Borrow& b) {
    os << "Borrowed " << b.getMovie()->getTitle() << " by " << b.getMovie()->getDirector();
    return os;
}