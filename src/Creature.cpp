#include "Creature.h"
#include <cstdlib>
#include <time.h>

#include "./Effects/Bleed.h"
#include <iostream>

void Creature::Draw() {
    DrawTexture(texture, position.x, position.y, WHITE);
}

// This won't be needed if we choose to have static
// ability selection for player and enemies.
// AKA starter creatures and enemies always have 
// abilities related to their type.
// For now though, this might be an interesting gameplay
// mechanic. 
//
// Also this is a horrible way of getting random unique
// abilities. This should probably be changed if it becomes
// a permanent feature.  
void Creature::GetRandomAbilities(std::vector<std::string> pool) {
    int count = 0;

    while (count < 4) {
        int r = rand() % pool.size();
        std::string pick = pool[r];
        bool found = false;
        for (std::string abl : abilities) {
            if (abl == pick) {
                found = true;
                break;
            }
        }
        if (!found) {
            abilities[count] = pool[r];
            count++;
        }
    }
}

bool Creature::IsDead() {
    return (health <= 0);
}

void Creature::CalculateEffects() {
    for (int i = 0; i < harmEffects.size(); i++) {
        (harmEffects[i])->effect();
    }

    for (int i = 0; i < helpEffects.size(); i++) {
        helpEffects[i]->effect();
    } 
}
