#pragma once
#include <cstdlib>
#include <ctime>

class Dice {
public:
    int diceCount;
    int minVal = 1;
    int maxVal = 6;

    Dice(int diceCount) : diceCount(diceCount) {
        srand(time(nullptr));
    }

    int rollDice() {

        int totalSum = 0;
        int diceUsed = 0;

        while (diceUsed < diceCount) {

            totalSum += minVal + (rand() % (maxVal - minVal + 1));
            diceUsed++;
        }

        return totalSum;
    }
};
