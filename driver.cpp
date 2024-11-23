#include "moviefactory.h"
#include "customerfactory.h"
#include "transactionfactory.h"
#include "movietable.h"
#include "customertable.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // Read movies into hashtable
    ifstream infile("data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	MovieTable movieTable(100);
	while (!infile.eof()) {
		string line;
		getline(infile, line);
		Movie* movie = MovieFactory::createMovie(line);
		if (movie != nullptr) {
			movieTable.insert(movie);
		}
	}
	movieTable.print();

	// Read customers into hashtable
	ifstream infile2("data4customers.txt");
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
	customerTable.print();

	// Read transactions and process
	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	while (!infile3.eof()) {
		string line;
		getline(infile3, line);
		Transaction* transaction = TransactionFactory::createTransaction(line, movieTable, customerTable);
		if (transaction != nullptr) {
			transaction->doTransaction(movieTable, customerTable);
		}
	}
	return 0;
}