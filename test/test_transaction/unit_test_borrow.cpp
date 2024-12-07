#include <gtest/gtest.h>
#include "unit_test_transaction_helper.h"

TEST(Borrow, negative_id) {
    // Movie* mov = new Comedy(10, "Jhon Beard", "Steven Mould", 1950);
    // Customer* customer = new Customer(1125,"Johnathan","Everson");
    // TransactionCase borrow;
    //
    // Borrow actual = Borrow(-1458, 'D','C', mov);
    // borrow.comedy_tree.insert(mov);
    // borrow.customer_table.insert(customer);
    //
    // actual.doTransaction(borrow.comedy_tree,borrow.drama_tree,borrow.classics_tree,borrow.customer_table);
    // EXPECT_TRUE(borrow.comedy_tree.get(mov->getSortingKey(),mov)); //TODO: fix this test case
}

TEST(Borrow, non_dvd_media) {

}

TEST(Borrow, invalid_movie_type) {

}

TEST(Borrow, empty_borrow_movie) {

}