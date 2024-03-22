#include "HealthPotion.h"
#include "../Creature.h"
#include "../util.h"

HealthPotion::HealthPotion() {
    name = "Health Potion";
    modifiers = {
        {Health, 3}
    };
    position = (Vector2){0.f, 0.f};
    texture = SetTexture("./textures/healthPotion.png", 32, 32);
}

HealthPotion::HealthPotion(HealthPotion* ref) {
    name = ref->name;
    modifiers = ref->modifiers;
}

void HealthPotion::effect() {
    target->health += modifiers[Health];
}
