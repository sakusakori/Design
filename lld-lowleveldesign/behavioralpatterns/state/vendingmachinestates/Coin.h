#pragma once

struct Coin {
    int value;
    Coin(int v) : value(v) {}
};

// Predefined coin types
const Coin PENNY(1);
const Coin NICKEL(5);
const Coin DIME(10);
const Coin QUARTER(25);
