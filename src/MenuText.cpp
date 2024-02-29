#include "MenuText.h"

// This isn't needed
void MenuText::Draw() {
    DrawText(this->text.c_str(), this->position.x, 
            this->position.y, this->size, this->color);
}
