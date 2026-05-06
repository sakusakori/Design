#pragma once
#include <string>
using namespace std;

enum PieceType {
    X,
    O
};

// Helper to convert PieceType to string (like Java's .name())
inline string pieceTypeName(PieceType type) {
    switch (type) {
        case X: return "X";
        case O: return "O";
        default: return "?";
    }
}
