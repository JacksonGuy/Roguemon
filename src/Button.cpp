#include "Button.h"

void Button::Draw() {
    DrawTexture(this->background, this->position.x, this->position.y, WHITE);
}

