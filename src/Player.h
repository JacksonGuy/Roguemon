#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "raylib.h"

#include "Creature.h"
#include "Item.h"

class Player : public Creature {
    public:
        std::vector<Item*> items;
        std::vector<Item*> inventory;

        Player(float x, float y);
        void move();
        void levelUp();
        void addItem(Item* item);
        void addInventory(Item* item);
};

#endif
