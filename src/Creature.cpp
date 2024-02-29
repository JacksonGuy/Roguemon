#include "Creature.h"

void Creature::Draw() {
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}