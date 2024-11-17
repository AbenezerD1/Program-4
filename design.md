# Designing a movie inventory  tracking system

## Priorities:
* Able to very quickly search for an movie
* Easily search using all movie characteristics
* modular design so it is easy to iterate on
* Invalidates improper inputs and prints the error
* prints the error if input could cause an error and stop the operation
* Takes very small amount of memory/memory efficient

## CURRENT IDEA

### Movie creation:
A Movie factory
- creates movies objects

Movie class
- stores(protected)
  - title 
  - genre
  - director
  - year it released
- getter
  - getTitle
  - getGenere
  - getReleaseDate
  - getDirectorName
- comparison operator overloaded to compare year it was released
- virtual destructor

Comedy class is a child class of the Movie class
- has constructor that initializes movie data

Drama class is a child class of the Movie class
- has constructor that initializes movie data

Classics class is a child class of the Movie class
- has constructor that initializes movie data and the major actor info
- stores additional major actor info
- contains a getter for major actor info

### Inventory Manager:
- handles inventory and transactions
- has a Inventory
- has customers 
- methods
  - buildInventory
  - addCustomers
  - processCommands

### Inventory:
- Use hashmap for movie storage
- the data has a pair of movie ptr and count of the movie
- the key would be a unique id of each movie

### Transaction handling:
TransactionContext:
- has a ptr to inventory and ptr to customers
- switches between different transactions and calls the process transaction

TransactionStrategies
- creates pure virtual method processTranscation

Borrow
  - perform transaction and add to customer history
Withdraw
  - perform transaction
Inventory
  - prints current inventory
History
  - prints current history of a customer
	

