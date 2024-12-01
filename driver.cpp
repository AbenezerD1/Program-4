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

using namespace std;

int main() {
    // Read movies into hashtable
    ifstream infile("/Users/spatiejunas/Documents/UW/Sophomore/AU24/CSS343/Program 4/datafiles/data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	// MovieTable movieTable(100);
	BST<Movie> comedyTree;
	BST<Movie> dramaTree;
	BST<Movie> classicsTree;
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

	// Read customers into hashtable
	ifstream infile2("/Users/spatiejunas/Documents/UW/Sophomore/AU24/CSS343/Program 4/datafiles/data4customers.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	CustomerTable customerTable(100);
	while (!infile2.eof()) {
		string line;
		getline(infile2, line);
		Customer* customer = CustomerFactory::createCustomer(line);
		if (customer != nullptr) {
			customerTable.insert(customer);
		}
	}

	// Read transactions and process
	ifstream infile3("/Users/spatiejunas/Documents/UW/Sophomore/AU24/CSS343/Program 4/datafiles/data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	std::vector<Transaction*> transactions;
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
	return 0;
}