#pragma once
#include "Item.h"

class ItemShelf {
public:
    int code;
    Item* item;
    bool soldOut;

    ItemShelf() : code(0), item(nullptr), soldOut(true) {}

    int getCode() { return code; }
    void setCode(int code) { this->code = code; }

    Item* getItem() { return item; }
    void setItem(Item* item) { this->item = item; }

    bool isSoldOut() { return soldOut; }
    void setSoldOut(bool soldOut) { this->soldOut = soldOut; }
};
