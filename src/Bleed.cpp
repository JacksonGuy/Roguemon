#include "Bleed.h"
#include <iostream>
#include <time.h>
#include "Creature.h"

Bleed::Bleed(std::string name, Creature* target, int duration, int damage) {
    this->name = name;
    this->target = target;
    this->id = time(0);
    this->duration = duration;
    this->damage = damage;
}

void Bleed::effect() {
    target->health -= this->damage;
    duration -= 1;
    if (this->duration <= 0) {
        delete(this);
    }
}

Bleed::~Bleed() {
    for (int i = 0; i < target->harmEffects.size(); i++) {
        if (target->harmEffects[i]->id == this->id) {
            std::cout << "Bleed expired" << std::endl;
            target->harmEffects.erase(target->harmEffects.begin() + i);
            return;
        }
    }
}
