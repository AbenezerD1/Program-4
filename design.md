# Movie Inventory tracking system

## Priorities:
* Able to quickly search for a customer with hashtable
* Easily search using all movie characteristics
* Modular design so it is easy to iterate on
* Invalidates improper inputs and prints the error
* Prints the error if input could cause an error and skip operation
* Is memory efficient

## Design Overview

### Driver
  * Instantiates three BSTs of Movies (Comedy, Drama, Classics) from a text file
  * Instantiates a hashtable of Customers from a text file
  * Creates Transactions and calls their doTransaction() to do the transaction

### Movie creation:
* **BST<Movie>**
  * Has a BSTNode ptr to root node
    * BSTNode struct
    * Movie ptr data
  * BSTNode ptr to left node
  * BSTNode ptr to left node
  * insert() method that takes Movie ptr and inserts based on sorting criteria
  * get() method that takes string key and Movie ptr, returns true if found
  * print() method that prints each movie in sorted order
* **MovieFactory**
  * Has static method createMovie that creates movie objects
  * Allows us to easily add different types of movies without modifying the driver code
* Movie
  * A object that has a title, genre, stock, director, and year
  * Contains functions that increase and decrease the stock
  * Has virtual sorting key function for BST to sort it by
  * Base class to all movies
  * Overloads the comparison operators \== and \!=
  * Overloads the output operator <<
  * Contains a virtual destructor
* Comedy
  * Derived class of Movie that behaves same as a Movie
* Drama
  * Derived class of Movie that behaves same as a Movie
* Classics
  * Derived class of Movie
  * Contains the first name and last name of the major actor
  * Contains the month of release of the movie
  * Overloads and overrides the comparison operators \== and \!=
  * Overloads and overrides the output operator

### Customers:
* **CustomerTable**
  * Contains a vector of list of Customer ptr
    * CustomerNode struct
      * Key is customer ID
      * Value is Customer object ptr
  * Contains a capacity that keeps track of current hashtable
  * Private hash() function
  * insert() method that takes a key and a Customer ptr
  * get() method that takes a key and Customer ptr to return true if it is found in the hashtable
  * remove() method that takes a key and remove the Customer that is associated with the key
  * print() method that prints out all Customer in the hashtable
* **CustomerFactory**
  * Has static method createCustomers that creates customers objects
* Customer
  * Contains an ID number, first name, last name, and vector of transaction ptr for customer transaction history

### Transaction handling:
* **TransactionFactory**
  * Has static method createTransaction() that creates Transaction objects
* Transaction
  * Abstract base class that has a pure virtual doTransaction() method
  * doTransaction() takes in references to the Movie BSTs and a CustomerTable reference
* Borrow
  * Contains a customerID and reference to movie transaction vector of the customer
  * doTransaction()
    * If movie exists in inventory decrement count from inventory
    * Adds transaction to customers history
* Return
  * Contains a customerID and reference to movie transaction vector of the customer
  * doTransaction method
    * If movie exists in inventory increment count from inventory
* Inventory
  * doTransaction()
    * Prints the current movies in the inventory
* History
  * Contains a pointer to Customer object
  * doTransaction()
    * Prints all transactions by customer
	

