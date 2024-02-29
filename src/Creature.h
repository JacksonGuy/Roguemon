#ifndef CREATURE_H
#define CREATURE_H

#include "raylib.h"

enum CreatureType {
    None,

    Water,
    Fire,
    Grass,
    Electric
};

class Creature {
    public:
        int health;
        int maxHealth;
        Vector2 position;
        float speed;
        Texture2D texture;

        CreatureType type;
        int attack;
        int defense;
        int attackSpeed;

        void Draw();
};

#endif