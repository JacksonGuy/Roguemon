#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"
#include "Player.h"

class Enemy : public Creature {
    public:
        Enemy(float, float);
        std::string combatAI(Player& player);
};

#endif