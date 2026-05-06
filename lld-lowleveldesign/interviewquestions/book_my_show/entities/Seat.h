#pragma once
#include "../enums/SeatCategory.h"

class Seat {
private:
    int seatId;
    SeatCategory category;

public:
    Seat(int seatId, SeatCategory category)
        : seatId(seatId), category(category) {}

    int getSeatId() { return seatId; }
};
