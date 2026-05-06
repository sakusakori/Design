#include <iostream>
#include "File.h"
#include "Directory.h"
using namespace std;

// Step 4: Client code with Composite Pattern
int main() {
    cout << "======= Composite Design Pattern ======" << endl;

    // Create files
    File receipt("receipt.pdf");
    File invoice("invoice.pdf");
    File torrentLinks("torrentLinks.txt");
    File tomCruise("tomCruise.jpg");
    File dumbAndDumber("DumbAndDumber.mp4");
    File hangoverI("HangoverI.mp4");

    // Create directories
    Directory moviesDirectory("Movies");
    Directory comedyMovieDirectory("ComedyMovies");

    // Build the tree structure hierarchically
    moviesDirectory.add(&receipt);
    moviesDirectory.add(&invoice);
    moviesDirectory.add(&torrentLinks);
    moviesDirectory.add(&tomCruise);
    moviesDirectory.add(&comedyMovieDirectory);
    comedyMovieDirectory.add(&dumbAndDumber);
    comedyMovieDirectory.add(&hangoverI);

    // Display full structure
    moviesDirectory.printContents();

    return 0;
}
