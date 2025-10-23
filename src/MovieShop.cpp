//
// Created by abene on 12/4/2024.
//

#include "MovieShop.h"

MovieShop::MovieShop(string movie_file_name, string customers_file_name){
      process_movies("../src/datafiles/"+movie_file_name);
      process_customers("../src/datafiles/"+customers_file_name);
}

bool MovieShop::process_movies(string movie_file_name){
    // Read movies into hashtable
    ifstream infile(movie_file_name);
    if (!infile) {
        cout << "File could not be opened." << endl;
        return false;
    }
    while (!infile.eof()) {
        string line;
        getline(infile, line);
        Movie* movie = MovieFactory::createMovie(line);
        if (movie == nullptr) {
            continue;
        }
        if (movie->getGenre() == 'F') {
            comedyTree.insert(movie);
        }
        else if (movie->getGenre() == 'D') {
            dramaTree.insert(movie);
        }
        else {
            classicsTree.insert(movie);
        }
    }
    return true;
}

bool MovieShop::process_customers(string customer_file_name){
    // Read customers into hashtable
    ifstream infile2(customer_file_name);
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return false;
    }

    while (!infile2.eof()) {
        string line;
        getline(infile2, line);
        Customer* customer = CustomerFactory::createCustomer(line);
        if (customer != nullptr) {
            customerTable.insert(customer);
        }
    }
    return true;
}

bool MovieShop::process_commands(string command_file_name){
    // Read transactions and process
    ifstream infile3("../src/datafiles/"+command_file_name);
    if (!infile3) {
        cout << "File could not be opened." << endl;
        return false;
    }
    // Transaction vector holding pointers to delete once done
    while (!infile3.eof()) {
        string line;
        getline(infile3, line);
        Transaction* transaction = TransactionFactory::createTransaction(line, comedyTree, dramaTree, classicsTree, customerTable);
        if (transaction != nullptr) {
            transactions.push_back(transaction);
            transaction->doTransaction(comedyTree, dramaTree, classicsTree, customerTable);
        }
    }
    for (auto t : transactions) {
        delete t;
    }
    return true;
}