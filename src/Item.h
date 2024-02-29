#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <map>
#include "raylib.h"

enum Modifier {
    // All creatures
    Health,
    Damage,
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
        std::map<std::string, int> modifiers; 
    
        // Cool feature:
        // Function pointer. Basically we'll have this point
        // to whatever item specific function and call it
        // during combat.
        void (*effect_func)();

        Vector2 position;
        Texture2D texture;

        Item();
};

#endif