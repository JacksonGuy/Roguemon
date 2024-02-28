#include "Player.h"
#include "raylib.h"

Player::Player(Vector2 pos) {
    this->setPosition(pos);
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