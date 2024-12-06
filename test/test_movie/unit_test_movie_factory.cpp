#include <gtest/gtest.h>
#include "../src/MovieShop.h"

TEST(moviefactory, create_movie){
    std::string str = "F, 10, Nora Ephron, Sleepless in Seattle, 1993";
    Movie* actual = MovieFactory::createMovie(str);
    Movie* expected = new Comedy(10,"Nora Ephron","Sleepless in Seattle",1993);

    EXPECT_EQ(*actual,*expected);
    delete actual;
    delete expected;
}
