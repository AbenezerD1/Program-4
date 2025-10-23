#include <gtest/gtest.h>
#include "drama.h"

TEST(Drama, construct_negative_stock) {
    Drama actual = Drama(-100, "Jhon Doe", "Title", 2000);

    EXPECT_EQ(actual.getStock(), 0);
}

TEST(Drama, decrement_stock) {
    Drama actual = Drama(3, "Jhon Doe", "Title", 2000);
    actual.decrementStock();
    EXPECT_EQ(actual.getStock(), 2);

    actual.decrementStock();
    actual.decrementStock();
    actual.decrementStock(); // should not make it go negative
    EXPECT_EQ(actual.getStock(), 0);
}

TEST(Drama, construct_non_string_director) {
    Drama actual[] = { Drama(0, "123*-+/a doe", "Title", 2000),
                        Drama(0, "Jhon b123*-+/", "Title", 2000),
                        Drama(0, "123*-+/ 245678c9?@#$", "Title", 2000) };

    EXPECT_EQ(actual[0].getDirector(), ""); // director first name is invalid
    EXPECT_EQ(actual[1].getDirector(), ""); // director last name is invalid
    EXPECT_EQ(actual[2].getDirector(), ""); // director first and last name is invalid
}

TEST(Drama, construct_non_string_title) {
    Drama actual = Drama(0, "Jhon Doe","123*-+/245678c9?@#$", 2000);
    EXPECT_EQ(actual.getTitle(), "");
}

TEST(Drama, construct_negative_year) {
    Drama actual = Drama(100, "Jhon Doe", "Title", -2000);
    EXPECT_EQ(actual.getYear(), 0);
}