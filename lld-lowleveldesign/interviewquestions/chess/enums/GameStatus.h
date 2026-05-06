#pragma once
#include <string>
using namespace std;

enum GameStatus {
    IN_PROGRESS,
    BLACK_WIN,
    WHITE_WIN,
    DRAW,
    RESIGNATION
};

inline string gameStatusName(GameStatus s) {
    switch (s) {
        case IN_PROGRESS: return "IN_PROGRESS";
        case BLACK_WIN: return "BLACK_WIN";
        case WHITE_WIN: return "WHITE_WIN";
        case DRAW: return "DRAW";
        case RESIGNATION: return "RESIGNATION";
        default: return "?";
    }
}
