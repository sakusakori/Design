#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Position.h"
#include "enums/PieceColour.h"
using namespace std;

int main() {
    cout << "\n###### LLD of Chess Game Demo ######" << endl;
    Player p1_white("Alice", WHITE);
    Player p2_black("Bob", BLACK);

    Game game(&p1_white, &p2_black);
    game.display();

    // Shortest Game: Fool's Mate Demo

    // Move 1: White[Pawn f2 -> f3]
    game.playMove(&p1_white, Position(1, 5), Position(2, 5));
    game.display();

    // Move 2: Black[Pawn e7 -> e5]
    game.playMove(&p2_black, Position(6, 4), Position(4, 4));
    game.display();

    // Move 3: White[Pawn g2 -> g4]
    game.playMove(&p1_white, Position(1, 6), Position(3, 6));
    game.display();

    // Move 4: Black[Queen d8 -> h4]
    game.playMove(&p2_black, Position(7, 3), Position(3, 7));
    game.display();

    // Move 5: White[Pawn a2 -> a3]
    game.playMove(&p1_white, Position(1, 0), Position(2, 0));
    game.display();

    // Move 6: Black[Queen h4 -> e1] [Checkmate]
    game.playMove(&p2_black, Position(3, 7), Position(0, 4));

    cout << "\nMoves History: " << endl;
    game.displayMovesHistory();
    cout << "\nGame demo completed!" << endl;

    return 0;
}
