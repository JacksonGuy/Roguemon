#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "raylib.h"

#include "Creature.h"
#include "Item.h"

class Player : public Creature {
    public:
        std::vector<Item> items;
        float critChance;
        float blackChance; 

        Player(float, float);
        void move();
};

#endif