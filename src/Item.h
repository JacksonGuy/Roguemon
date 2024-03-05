#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <map>
#include "raylib.h"

enum Modifier {
    // All creatures
    Health,
    Attack,
    Defense,
    AttackSpeed,

    // Player Specific
    CritChance,
    BlockChance
};

class Item {
    public:
        std::string name;

        // String = stat, int = how to modify (+/-)
        std::map<Modifier, int> modifiers; 

        Vector2 position;
        Texture2D texture;

        virtual void effect() = 0;
        Item() {};
        Item(Item* ref) {};
};

#endif