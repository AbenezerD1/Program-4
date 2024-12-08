//
// Created by abene on 12/6/2024.
//

#ifndef UNIT_TEST_TRANSACTION_HELPER_H
#define UNIT_TEST_TRANSACTION_HELPER_H
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "customer.h"

class TransactionCase{
    public:
    TransactionCase() = default;

    void insertComedyMovies(std::vector<Movie*>& vec){
        for(Movie*& mov: vec){
            comedy_tree.insert(mov);
        }
    }

    void insertDramaMovies(std::vector<Movie*>& vec){
        for(Movie*& mov: vec){
            drama_tree.insert(mov);
        }
    }

    void insertClassicsMovies(std::vector<Movie*>& vec){
        for(Movie*& mov: vec){
            classics_tree.insert(mov);
        }
    }

    void insertCustomers(std::vector<Customer*>& vec){
        for(Customer*& customer: vec){
            customer_table.insert(customer);
        }
    }

    void defaultInventorySetUp(){
        std::vector<Movie*> comedies = {
                                    new Comedy(65, "Thanh Parker", "Fragments of Yesterday", 1955),
                                    new Comedy(13, "Terry Powers", "Gale Force Warriors", 1989),
                                    new Comedy(1, "Stacy Curtis", "A Dance with Stardust", 2005)
                                  };
        std::vector<Movie*> dramas = {
                                        new Drama(65, "Freda Stevenson", "Chasing Nebulas", 1965),
                                        new Drama(65, "Maureen Donovan", "Whispers in the Storm", 1940),
                                        new Drama(65, "Allen Woody", "The Enchanted Astronaut", 2000) 
                                    };

        std::vector<Movie*> classics = {    new Classics(3, "Zane  Adams", "Galactic Nomads", "Judy","Garland", 2, 2013),
                                            new Classics(3, "Jhon Doe", "The Labyrinth of Shadows", "Rueben ","Gonzales", 5, 2018),
                                            new Classics(3, "Latoya  Middleton", "Galactic Whispers: The Orion Chronicles", "Allie ","Mosley", 7, 2024)
                                        };
        insertComedyMovies(comedies);
        insertDramaMovies(dramas);
        insertClassicsMovies(classics);
    }

    void defaultCustomerSetUp(){
        std::vector<Customer*> customers = {    new Customer(1120,"Jhon","Doe"),
                                                new Customer(3025,"Alex","Nat"),
                                                new Customer(9825,"Steven","Star")
                                            };
        insertCustomers(customers);
    }

    BST<Movie> comedy_tree = BST<Movie>();
    BST<Movie> drama_tree = BST<Movie>();
    BST<Movie> classics_tree = BST<Movie>();
    CustomerTable customer_table = CustomerTable(11);
};

#endif //UNIT_TEST_TRANSACTION_HELPER_H
