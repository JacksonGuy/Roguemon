#include "Enemy.h"

// TODO change how enemy stats are generated 
Enemy::Enemy(float x, float y) {
    this->position = (Vector2){x, y};
    this->level = 1;
    this->health = 10;
    this->maxHealth = 10;
    this->speed = 5.f;

    // TODO make this random
    this->type = Grass;
}

std::string Enemy::combatAI(Player& player) {
    int r = rand() % 4; 
    return this->abilities[r];
}