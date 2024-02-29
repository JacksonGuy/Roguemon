#include "Player.h"
#include "raylib.h"

Player::Player(float x, float y) {
    this->position = (Vector2){x, y};
    this->health = 10;
    this->maxHealth = 10;
    this->speed = 5.f;
}

void Player::move() {
    if (IsKeyDown(KEY_W)) {
        this->position.y -= this->speed;
    } 
    if (IsKeyDown(KEY_S)) {
        this->position.y += this->speed;
    }
    if (IsKeyDown(KEY_A)) {
        this->position.x -= this->speed;
    }
    if (IsKeyDown(KEY_D)) {
        this->position.x += this->speed;
    }
}
