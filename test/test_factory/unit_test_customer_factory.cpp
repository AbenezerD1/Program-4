#include <gtest/gtest.h>
#include "customerfactory.h"

TEST(CustomerFatory, invalid_id) {
    std::string str = "-3333 Witch Wicked";

    Customer* actual = CustomerFactory::createCustomer(str);
    EXPECT_EQ(actual->getID(), 0);
}



