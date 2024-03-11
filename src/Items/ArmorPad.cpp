#include "ArmorPad.h"
#include "../util.h"

ArmorPad::ArmorPad() {
    name = "Armor Pad";
    modifiers = {
        {Defense, 1},
        {BlockChance, 1} // Remember, this is a percentage
    };

    position = (Vector2){0,0};
    //texture = SetTexture("./src/Items/textures/testArmor.png", 64, 64);
}

ArmorPad::ArmorPad(ArmorPad* ref) {
    name = ref->name;
    modifiers = ref->modifiers;
}

void ArmorPad::effect() {
    return;
}
