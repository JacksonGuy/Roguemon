#include "Player.h"
#include "raylib.h"

Player::Player(int x, int y) {
    Vector2 vec = {x, y};
    this->setPosition(vec);
}

void Player::setPosition(Vector2 newpos) {
    this->position = newpos;
}
Vector2 Player::getPosition() {
    return this->position;
}

void Player::setTexture(Texture2D& texture) {
    this->texture = texture;
}
Texture2D Player::getTexture() {
    return this->texture;
}