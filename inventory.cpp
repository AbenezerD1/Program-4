#include "inventory.h"

void Inventory::doTransaction(BST<Movie>& comedyTree, BST<Movie>& dramaTree, BST<Movie>& classicsTree, CustomerTable& customerTable) {
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Comedies:" << std::endl;
    std::cout << std::endl;
    std::cout << "Genre   Media   Title                              Director              Year    Stock" << std::endl;
    comedyTree.print();
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Dramas:" << std::endl;
    std::cout << std::endl;
    std::cout << "Genre   Media   Title                              Director              Year    Stock" << std::endl;
    dramaTree.print();
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Classics:" << std::endl;
    std::cout << std::endl;
    std::cout << "Genre   Media   Title                              Director              Month   Year    Stock" << std::endl;
    classicsTree.printClassics();
    std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}