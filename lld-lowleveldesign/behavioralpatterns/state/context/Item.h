#pragma once
#include "ItemType.h"

class Item {
public:
    ItemType type;
    int price;

    Item() : type(COKE), price(0) {}

    ItemType getType() { return type; }
    void setType(ItemType type) { this->type = type; }

    int getPrice() { return price; }
    void setPrice(int price) { this->price = price; }
};
