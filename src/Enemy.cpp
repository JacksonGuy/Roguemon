#include "Enemy.h"

// TODO change how enemy stats are generated 
Enemy::Enemy(float x, float y) {
    this->position = (Vector2){x, y};
    this->health = 10;
    this->maxHealth = 10;
    this->speed = 5.f;
}