#include <gtest/gtest.h>
#include "moviefactory.h"

TEST(MovieFactory, create_comedy_movie){
    std::string str[] = {"F, 10, Nora Ephron, Sleepless in Seattle, 1993",
                    "F, 10, Woody Allen, Annie Hall, 1977",
                    "F, 10, Joel Coen, Fargo, 1996",
                    "F, 10, Nora Ephron, You've Got Mail, 1998"
                    };
    Comedy* actual[] = {    dynamic_cast<Comedy *>(MovieFactory::createMovie(str[0])),
                            dynamic_cast<Comedy *>(MovieFactory::createMovie(str[1])),
                            dynamic_cast<Comedy *>(MovieFactory::createMovie(str[2])),
                            dynamic_cast<Comedy *>(MovieFactory::createMovie(str[3]))
                        };

    Comedy expected[] = {   Comedy(10,"Nora Ephron","Sleepless in Seattle",1993),
                            Comedy(10,"Woody Allen","Annie Hall",1977),
                            Comedy(10,"Joel Coen","Fargo",1996),
                            Comedy(10,"Nora Ephron","You've Got Mail",1998)
                        };

    for (int i = 0; i < sizeof(actual) / sizeof(actual[0]); i++) {
        EXPECT_EQ(*actual[i],expected[i]) << *actual[i] << expected[i];
    }

    for (Comedy* obj : actual) {
        if (obj == nullptr) continue;
        delete obj;
    }
}

TEST(MovieFactory, create_drama_movie) {
    std::string str[] = {"D, 10, Barry Levinson, Good Morning Vietnam, 1988",
                    "D, 10, Gus Van Sant, Good Will Hunting, 2000",
                    "D, 10, Nancy Savoca, Dogfight, 1991",
                    "D, 10, Clint Eastwood, Unforgiven, 1992"
                    };
    Drama* actual[] = {    dynamic_cast<Drama *>(MovieFactory::createMovie(str[0])),
                            dynamic_cast<Drama *>(MovieFactory::createMovie(str[1])),
                            dynamic_cast<Drama *>(MovieFactory::createMovie(str[2])),
                            dynamic_cast<Drama *>(MovieFactory::createMovie(str[3]))
                        };

    Drama expected[] = {   Drama(10,"Barry Levinson","Good Morning Vietnam",1988),
                            Drama(10,"Gus Van Sant","Good Will Hunting",2000),
                            Drama(10,"Nancy Savoca","Dogfight",1991),
                            Drama(10,"Clint Eastwood","Unforgiven",1992)
                        };

    for (int i = 0; i < sizeof(actual) / sizeof(actual[0]); i++) {
        EXPECT_EQ(*actual[i],expected[i]);
    }

    for (Drama* obj : actual) {
        if (obj == nullptr) continue;
        delete obj;
    }
}

TEST(MovieFactory, create_classics_movie) {
    std::string str[] = {"C, 10, Victor Fleming, Gone With the Wind, Vivien Leigh 2 1939",
                    "C, 10, Victor Fleming, Gone With the Wind, Clark Gable 2 1939",
                    "C, 10, George Cukor, The Philadelphia Story, Katherine Hepburn 5 1940",
                    "C, 10, George Cukor, The Philadelphia Story, Cary Grant 5 1940"
                    };
    Classics* actual[] = {  dynamic_cast<Classics *>(MovieFactory::createMovie(str[0])),
                            dynamic_cast<Classics *>(MovieFactory::createMovie(str[1])),
                            dynamic_cast<Classics *>(MovieFactory::createMovie(str[2])),
                            dynamic_cast<Classics *>(MovieFactory::createMovie(str[3]))
                         };

    Classics expected[] = { Classics(10,"Victor Fleming", "Gone With the Wind","Vivien","Leigh",2,1939),
                            Classics(10,"Victor Fleming", "Gone With the Wind", "Clark"," Gable", 2, 1939),
                            Classics(10,"George Cukor","The Philadelphia Story", "Katherine", "Hepburn", 5, 1940),
                            Classics(10, "George Cukor", "The Philadelphia Story", "Cary", "Grant",5,1940)
                          };

    for (int i = 0; i < sizeof(actual) / sizeof(actual[0]); i++) {
        EXPECT_TRUE(*actual[i] == expected[i]) << *actual[i] << std::endl << expected[i];
    }

    for (Classics* obj : actual) {
        if (obj == nullptr) continue;
        delete obj;
    }
}