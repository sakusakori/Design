#pragma once
#include <vector>
#include <stdexcept>
#include "Item.h"
#include "ItemShelf.h"
using namespace std;

class Inventory {
public:
    vector<ItemShelf*> inventory;

    Inventory(int itemCount) {
        inventory.resize(itemCount);
        initialEmptyInventory();
    }

    vector<ItemShelf*>& getInventory() { return inventory; }

    void initialEmptyInventory() {
        int startCode = 101;
        for (int i = 0; i < (int)inventory.size(); i++) {
            ItemShelf* space = new ItemShelf();
            space->setCode(startCode);
            space->setSoldOut(true);
            inventory[i] = space;
            startCode++;
        }
    }

    void addItem(Item* item, int codeNumber) {
        for (ItemShelf* itemShelf : inventory) {
            if (itemShelf->code == codeNumber) {
                if (itemShelf->isSoldOut()) {
                    itemShelf->item = item;
                    itemShelf->setSoldOut(false);
                } else {
                    throw runtime_error("already item is present, you can not add item here");
                }
            }
        }
    }

    Item* getItem(int codeNumber) {
        for (ItemShelf* itemShelf : inventory) {
            if (itemShelf->code == codeNumber) {
                if (itemShelf->isSoldOut()) {
                    throw runtime_error("item already sold out");
                } else {
                    return itemShelf->item;
                }
            }
        }
        throw runtime_error("Invalid Code");
    }

    void updateSoldOutItem(int codeNumber) {
        for (ItemShelf* itemShelf : inventory) {
            if (itemShelf->code == codeNumber) {
                itemShelf->setSoldOut(true);
            }
        }
    }
};
