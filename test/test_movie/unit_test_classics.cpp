#include <gtest/gtest.h>
#include "classics.h"

TEST(Classics, construct_negative_stock) {
    Classics actual = Classics(-10, "Jhon Doe", "Title", "Judy","Garland", 7, 1939);

    EXPECT_EQ(actual.getStock(), 0);
}

TEST(Classics, decrement_stock) {
    Classics actual = Classics(3, "Jhon Doe", "Title", "Judy","Garland", 7, 1939);
    actual.decrementStock();
    EXPECT_EQ(actual.getStock(), 2);

    actual.decrementStock();
    actual.decrementStock();
    actual.decrementStock(); // should not make it go negative
    EXPECT_EQ(actual.getStock(), 0);
}

TEST(Classics, construct_non_string_director) {
    Classics actual[] = {   Classics(10, "123* Doe", "Title", "Judy","Garland", 7, 1939),
                            Classics(10, "Jhon -+/2456", "Title", "Judy","Garland", 7, 1939),
                            Classics(10, "123* 5678", "Title", "Judy","Garland", 7, 1939)
                        };

    EXPECT_EQ(actual[0].getDirector(), ""); // director first name is invalid
    EXPECT_EQ(actual[1].getDirector(), ""); // director last name is invalid
    EXPECT_EQ(actual[2].getDirector(), ""); // director first and last name is invalid
}

TEST(Classics, construct_non_string_title) {
    Classics actual = Classics(10, "Jhon Doe", "123*-+/245678c9?@#$", "Judy","Garland", 7, 1939);
    EXPECT_EQ(actual.getTitle(), "");
}

TEST(Classics, construct_negative_year) {
    Classics actual = Classics(10, "Jhon Doe", "Title", "Judy","Garland", 7, -1939);

    EXPECT_EQ(actual.getYear(), 0);
}

TEST(Classics, equal_operator) {
    Classics actual[] = {   Classics(10, "Jhon Doe", "Title", "Judy","Garland", 7, 1939),
                            Classics(10, "Jhon Doe", "Title", "Judy","Garland", 7, 1939)
                        };
    EXPECT_TRUE(actual[0] == actual[1]);
}

TEST(Classics, not_equal_operator) {
    Classics actual[] = {   Classics(10, "Adam Savage", "Walls", "Rob","Reiner", 7, 2020),
                            Classics(10, "Jhon Doe", "Title", "Judy","Garland", 7, 1939)
                        };
    EXPECT_TRUE(actual[0] != actual[1]);
}