#include "MovieShop.h"
#include <string>

int main(int argc, char *argv[]) {
    MovieShop blockbuster("data4movies.txt","data4customers.txt");
    blockbuster.process_commands("data4commands.txt");
}