//
// Created by abene on 12/6/2024.
//

#ifndef UNIT_TEST_TRANSACTION_HELPER_H
#define UNIT_TEST_TRANSACTION_HELPER_H
#include "borrow.h"
#include "customer.h"

class TransactionCase{
    public:
    TransactionCase() = default;

    BST<Movie> comedy_tree = BST<Movie>();
    BST<Movie> drama_tree = BST<Movie>();
    BST<Movie> classics_tree = BST<Movie>();
    CustomerTable customer_table = CustomerTable(10);
};

#endif //UNIT_TEST_TRANSACTION_HELPER_H
