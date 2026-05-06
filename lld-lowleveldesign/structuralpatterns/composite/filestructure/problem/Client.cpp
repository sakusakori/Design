#include <iostream>
#include "Directory.h"
#include "File.h"
using namespace std;

// Client Code
int main() {
    Directory_Problem movieDirectory("Movies");

    File_Problem rentalReceipt("RentalReceipt");
    movieDirectory.addFile(&rentalReceipt);

    Directory_Problem comedyMovieDirectory("ComedyMovies");
    File_Problem dumbAndDumber("DumbAndDumber");
    comedyMovieDirectory.addFile(&dumbAndDumber);
    movieDirectory.addDirectory(&comedyMovieDirectory);

    movieDirectory.printContents();

    return 0;
}
