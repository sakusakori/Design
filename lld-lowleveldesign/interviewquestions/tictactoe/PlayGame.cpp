#include <iostream>
#include "TicTacToeGame.h"
using namespace std;

int main() {
    cout << "\n===>>> TicTacToe Game\n" << endl;
    TicTacToeGame game;
    game.initializeGame();
    GameStatus status = game.startGame();
    cout << "\n===>>> GAME OVER: ";
    switch (status) {
        case WIN:
            cout << game.winner->name << " won the game";
            break;
        case DRAW:
            cout << " Its a Draw!";
            break;
        default:
            cout << " Game Ends";
            break;
    }
    cout << endl;

    return 0;
}
