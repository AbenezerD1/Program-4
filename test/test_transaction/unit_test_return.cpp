#include <gtest/gtest.h>
#include "unit_test_transaction_helper.h"

TEST(Returns, negative_customer_id) {
    Movie* mov = new Comedy(65, "Allen Woody", "Hall Annie", 1965);
    Customer* customer = new Customer(1234,"Jhon","Doe");
    TransactionCase return_case;

    return_case.comedy_tree.insert(mov);
    return_case.customer_table.insert(customer);

    Return trans = Return(-1005,'D','F',mov);

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);
    
    EXPECT_EQ(customer->getTransactionHistory(),std::vector<Transaction*>());
}

TEST(Returns, empty_customer_table) {
    TransactionCase return_case;
    return_case.defaultInventorySetUp();
    
    Movie* mov = new Comedy(65, "Thanh Parker", "Fragments of Yesterday", 1955);
    Return trans = Return(1120,'D','F',mov); //should be valid

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Movie* actual;
    return_case.comedy_tree.get(mov->getSortingKey(),actual);

    EXPECT_EQ(*actual,*mov);
    delete mov;
}

TEST(Returns, empty_inventory){
    TransactionCase return_case;
    return_case.defaultCustomerSetUp();

    Movie* mov = new Comedy(65, "Thanh Parker", "Fragments of Yesterday", 1955);
    Return trans = Return(1120,'D','F',mov);

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Movie* actual;
    return_case.comedy_tree.get(mov->getSortingKey(),actual);

    EXPECT_EQ(actual, nullptr);
    delete mov;
}

TEST(Returns, null_movie) {
    TransactionCase return_case;
    return_case.defaultInventorySetUp();
    return_case.defaultCustomerSetUp();

    Movie* mov = nullptr;
    Return trans = Return(1120,'D','F',mov); // customer id 1120 is in customer table

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Movie* actual;

    EXPECT_FALSE(return_case.comedy_tree.get("",actual));
    delete mov;
}


TEST(Returns, comedy_movie){
    TransactionCase return_case;
    return_case.defaultInventorySetUp();
    return_case.defaultCustomerSetUp();

    Movie* mov = new Comedy(65, "Thanh Parker", "Fragments of Yesterday", 1955);
    Return trans = Return(1120,'D','F',mov); //should be valid

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Customer* customer;
    return_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Return*>(actual[0])->getMovie(), *mov);
    delete mov;
}

TEST(Returns, drama_movie){
    TransactionCase return_case;
    return_case.defaultInventorySetUp();
    return_case.defaultCustomerSetUp();

    Movie* mov = new Drama(65, "Freda Stevenson", "Chasing Nebulas", 1965);
    Return trans = Return(1120,'D','F',mov); //should be valid

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Customer* customer;
    return_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Return*>(actual[0])->getMovie(), *mov);
    delete mov;
}

TEST(Returns, classics_movie){
    TransactionCase return_case;
    return_case.defaultInventorySetUp();
    return_case.defaultCustomerSetUp();

    Movie* mov = new Classics(3, "Latoya  Middleton", "Galactic Whispers: The Orion Chronicles", "Allie ","Mosley", 7, 2024);
    Return trans = Return(1120,'D','F',mov); //should be valid

    trans.doTransaction(return_case.comedy_tree,
                        return_case.drama_tree,
                        return_case.classics_tree,
                        return_case.customer_table);

    Customer* customer;
    return_case.customer_table.get(1120,customer);
    std::vector<Transaction*> actual = customer->getTransactionHistory();
    EXPECT_EQ(*dynamic_cast<Return*>(actual[0])->getMovie(), *mov);
    delete mov;
}