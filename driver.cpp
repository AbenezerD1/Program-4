#include "moviefactory.h"
#include "transactionfactory.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // read in movies first
    ifstream infile("data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
    MovieFactory movieFactory;

	ifstream infile2("data4customers.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	HashTable customerTable(100);

	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	TransactionFactory transactionFactory;
}