//
// Created by abene on 12/4/2024.
//

#ifndef MOVIESHOP_H
#define MOVIESHOP_H
#include "moviefactory.h"
#include "customerfactory.h"
#include "transactionfactory.h"
#include "bst.h"
#include "customertable.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class MovieShop {
    private:
        BST<Movie> comedyTree;
        BST<Movie> dramaTree;
        BST<Movie> classicsTree;
        CustomerTable customerTable = CustomerTable(100);
        std::vector<Transaction*> transactions;

        bool process_movies(std::string movie_file_name);
        bool process_customers(std::string customer_file_name);
    public:
        MovieShop(string movie_file_name, string customer_file_name);
        bool process_commands(std::string command_file_name);
};



#endif //MOVIESHOP_H
