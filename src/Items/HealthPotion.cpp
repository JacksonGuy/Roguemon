#include "./src/Items/HealthPotion.h"
#include "../Creature.h"

HealthPotion::HealthPotion() {
    name = "Health Potion";
    modifiers = {
        {Health, 3}
    };
    position = (Vector2){0.f, 0.f};
}

HealthPotion::HealthPotion(HealthPotion* ref) {
    name = ref->name;
    modifiers = ref->modifiers;
}

void HealthPotion::effect() {
    target->health += modifiers[Health];
}
