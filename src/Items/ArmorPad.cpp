#include "ArmorPad.h"

ArmorPad::ArmorPad() {
    name = "Armor Pad";
    modifiers = {
        {Defense, 1},
        {BlockChance, 1} // Remember, this is a percentage
    };
    position = (Vector2){0,0};
    
    Image image = LoadImage("./Items/textures/testArmor.png"); 
    texture = LoadTextureFromImage(image);
}

ArmorPad::ArmorPad(ArmorPad* ref) {
    name = ref->name;
    modifiers = ref->modifiers;
}

void ArmorPad::effect() {
    return;
}