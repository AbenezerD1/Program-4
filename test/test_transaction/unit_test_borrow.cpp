#include <gtest/gtest.h>
#include "unit_test_transaction_helper.h"

TEST(Borrow, negative_customer_id) {
    Movie* mov = new Comedy(65, "Allen Woody", "Hall Annie", 1965);
    Customer* customer = new Customer(1234,"Jhon","Doe");
    TransactionCase borrow_case;

    borrow_case.comedy_tree.insert(mov);
    borrow_case.customer_table.insert(customer);

    Borrow trans = Borrow(-1005,'D','F',mov);

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);
    
    EXPECT_EQ(customer->getTransactionHistory(),std::vector<Transaction*>());
}

TEST(Borrow, empty_inventory_non_empty_customer_table) {
    Movie* mov = new Comedy(65, "Allen Woody", "Hall Annie", 1965);
    Customer* customer = new Customer(1234,"Jhon","Doe");
    TransactionCase borrow_case;

    borrow_case.customer_table.insert(customer);

    Borrow trans = Borrow(-1005,'D','F',mov);

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);
    
    Movie* res;
    borrow_case.comedy_tree.get(mov->getSortingKey(),res);
    EXPECT_TRUE(mov != nullptr); //movie shouldn't exist

    delete res;
    delete mov;
}

TEST(Borrow, non_empty_inventory_empty_customer_table) {
    Movie* mov = new Comedy(65, "Allen Woody", "Hall Annie", 1965);
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();

    Borrow trans = Borrow(1005,'D','F',mov);

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Movie* actual;

    borrow_case.comedy_tree.get(mov->getSortingKey(),actual);

    EXPECT_TRUE(actual != nullptr); //customer shouldn't exist

    delete mov;
}

TEST(Borrow, null_movie) {
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();
    borrow_case.defaultCustomerSetUp();

    Movie* mov = nullptr;
    Borrow trans = Borrow(1120,'D','F',mov); // customer id 1120 is in customer table

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Customer* customer;
    borrow_case.customer_table.get(1120,customer);
    EXPECT_TRUE((*customer).getTransactionHistory().empty());
}

TEST(Borrow, movie_not_in_inventory){
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();
    borrow_case.defaultCustomerSetUp();

    Movie* mov = new Comedy(9, "Shane Powers", "Fish Force Warriors", 2001);
    Borrow trans = Borrow(1120,'D','F',mov); // customer id 1120 is in customer table

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Customer* customer;
    borrow_case.customer_table.get(1120,customer);
    EXPECT_TRUE((*customer).getTransactionHistory().empty());
    delete mov;
}

TEST(Borrow, comedy_movie){
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();
    borrow_case.defaultCustomerSetUp();

    Movie* mov = new Comedy(65, "Thanh Parker", "Fragments of Yesterday", 1955);
    Borrow trans = Borrow(1120,'D','F',mov); //should be valid

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Customer* customer;
    borrow_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Borrow*>(actual[0])->getMovie(), *mov);
    delete mov;
}

TEST(Borrow, drama_movie){
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();
    borrow_case.defaultCustomerSetUp();

    Movie* mov = new Drama(65, "Allen Woody", "The Enchanted Astronaut", 2000);
    Borrow trans = Borrow(1120,'D','F',mov); //should be valid

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Customer* customer;
    borrow_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Borrow*>(actual[0])->getMovie(), *mov);
    delete mov;
}

TEST(Borrow, classics_movie){
    TransactionCase borrow_case;
    borrow_case.defaultInventorySetUp();
    borrow_case.defaultCustomerSetUp();

    Movie* mov = new Classics(3, "Zane  Adams", "Galactic Nomads", "Judy","Garland", 2, 2013);
    Borrow trans = Borrow(1120,'D','F',mov); //should be valid

    trans.doTransaction(borrow_case.comedy_tree,
                        borrow_case.drama_tree,
                        borrow_case.classics_tree,
                        borrow_case.customer_table);

    Customer* customer;
    borrow_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Borrow*>(actual[0])->getMovie(), *mov);
    delete mov;
}