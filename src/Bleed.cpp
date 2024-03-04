#include "Bleed.h"
#include <iostream>
#include <time.h>
#include "Creature.h"

Bleed::Bleed(std::string name, int duration, int damage) {
    this->name = name;
    this->id = time(0);
    this->duration = duration;
    this->damage = damage;
}

void Bleed::active(Creature& target) {
    return;
}

void Bleed::effect(Creature& target) {
    std::cout << "2" << std::endl;
    if (this->duration <= 0) {
        this->deactive(target);
        return;
    }
    std::cout << "3" << std::endl;
    target.health -= this->damage;
    duration -= 1;
}

void Bleed::deactive(Creature& target) {
    for (int i = 0; i < target.harmEffects.size(); i++) {
        if (target.harmEffects[i]->id == this->id) {
            std::cout << "Bleed expired" << std::endl;
            target.harmEffects.erase(target.harmEffects.begin() + i);
            return;
        }
    }
}