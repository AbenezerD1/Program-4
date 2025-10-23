#include <gtest/gtest.h>
#include "customer.h"

TEST(Customer, negative_id) {
    Customer customer = Customer(-1651,"Beard","Jhon");
    Customer customer2 = Customer(-1,"Beard","Jhon");
    EXPECT_EQ(customer.getID(),0);
    EXPECT_EQ(customer2.getID(),0);
}


