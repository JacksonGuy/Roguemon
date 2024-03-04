#include "Creature.h"
#include <cstdlib>
#include <time.h>

#include "Bleed.h"
#include <iostream>

void Creature::Draw() {
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
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
    srand(time(0));

    while (count < 4) {
        int r = rand() % pool.size();
        std::string pick = pool[r];
        bool found = false;
        for (std::string abl : this->abilities) {
            if (abl == pick) {
                found = true;
                break;
            }
        }
        if (!found) {
            this->abilities[count] = pool[r];
            count++;
        }
    }
}

bool Creature::IsDead() {
    return (this->health <= 0);
}

void Creature::CalculateEffects() {
    std::cout << "Debuffs size: " << this->harmEffects.size() << std::endl;
    for (int i = 0; i < this->harmEffects.size(); i++) {
        std::cout << "1" << std::endl;
        (this->harmEffects[i])->effect(*this); // PROBLEM GUY HERE
        std::cout << "4" << std::endl;
    }
    std::cout << "It works!" << std::endl;

    /*
    for (Effect* e : helpEffects) {
        e->effect(*this);
    } 
    */
}