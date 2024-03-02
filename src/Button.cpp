#include "Button.h"

Button::Button(Vector2 pos, std::string text) {
    this->position = pos;
    this->text = text;
    this->GetRect();
}

void Button::GetRect() {
    int length = this->text.size() * this->size;
    this->rect = (Rectangle){this->position.x, this->position.y, (float)length, (float)this->size};
}

void Button::Draw() {
    DrawText(this->text.c_str(), this->position.x, this->position.y, this->size, this->color);
}