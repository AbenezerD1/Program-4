# Movie Inventory tracking system

## Priorities:
* Able to very quickly search for an movie
* Easily search using all movie characteristics
* modular design so it is easy to iterate on
* Invalidates improper inputs and prints the error
* prints the error if input could cause an error and stop the operation
* Takes very small amount of memory/memory efficient

## Design Overview

### Driver
  * Instantiates a hashtable of movies objects from a text file
  * Instantiates a hashtable of customer objects from a text file
  * Creates transaction objects and calls them to do the transaction

### Movie creation:
* **MovieTable**
  * Contains a vector of list of MovieNode ptr
    * MovieNode struct
      * Has a key
      * Has a Movie object
  * Contains a capacity that keeps track of current hashtable
  * Private hash function
  * Insert method that takes a key and a Movie ptr
  * Get method that takes a key and reference to a movie object to return the Movie object if it is found in the hashtable
  * Remove method that takes a key and remove the Movie that is associated with the key
  * Print method that prints out all Movies in the hashtable
* **MovieFactory**
  * Has static method createMovie that creates movie objects
  * Allows us to easily add different types of movies without modifying the driver code
* Movie
  * A object that has a title, genre, stock, director, and year
  * Contains a functions that increase and decrease the stock
  * Base class to all movies
  * Overloads the comparison operators \== and \!=
  * Overloads the output operator
  * Contains a Virtual destructor
* Comedy
  * Derived class of Movie that behaves same as a Movie
* Drama
  * Derived class of Movie that behaves same as a Movie
* Classics
  * Derived class of Movie
  * Contains the first name and last name of the major actor
  * Contains the month of release of the movie
  * Overloads the comparison operators \== and \!=
  * Overloads the output operator

### Customers:
* **CustomerTable**
  * Contains a vector of list of Customer ptr
    * CustomerNode struct
      * Has a key that is the customer ID
      * Has a Customer object
  * Contains a capacity that keeps track of current hashtable
  * Private hash function
  * Insert method that takes a key and a Customer ptr
  * Get method that takes a key and reference to a Customer object to return the Customer object if it is found in the hashtable
  * Remove method that takes a key and remove the Customer that is associated with the key
  * Print method that prints out all Customer in the hashtable
* **CustomerFactory**
  * Has static method createCustomers that creates customers objects
* Customer
  * Contains a id, first name, last name, and vector of movie ptr for customer history

### Transaction handling:
* **TransactionFactory**
  * Has static method createTransactions that creates transaction objects
* Transaction
  * Abstract class that has a doTransaction method
* Borrow
  * Contains a customerid and reference to movie transaction vector of the customer
  * doTransaction method
    * If movie exists in inventory decrement count from inventory
    * Adds transaction to customers history
* Return
  * Contains a customerid and reference to movie transaction vector of the customer
  * doTransaction method
    * If movie exists in inventory increment count from inventory
* Inventory
  * Contains a pointer to movie hash table
  * doTransaction method
    * Prints the current movies in the inventory
* History
  * Contains a pointer to Customer object
  * doTransaction method
    * Prints all transactions by customer
	

