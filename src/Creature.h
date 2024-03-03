#ifndef CREATURE_H
#define CREATURE_H

#include "raylib.h"
#include <string>
#include <vector>

#include "Effect.h"

enum CreatureType {
    None,

    Water,
    Fire,
    Grass,
    Electric
};

class Creature {
    public:
        Vector2 position;
        float speed;
        Texture2D texture;

        CreatureType type;
        int health = 1;
        int maxHealth = 1;

        int level = 1;
        int xp = 0;
        int nextLevelXp = 10;
        int attack = 1;
        int defense = 1;
        int attackSpeed = 1;

        float critChance = 0;
        float blockChance = 0; 

        // Basically just a list of all usable abilities
        std::string abilities[4]; // Maximum 4 usable abilities

        std::vector<Effect> harmEffects;
        std::vector<Effect> helpEffects;

        void Draw();
        void GetRandomAbilities(std::vector<std::string>);
        bool IsDead();
};

#endif