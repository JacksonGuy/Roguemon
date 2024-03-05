#include "Player.h"
#include "raylib.h"

Player::Player(float x, float y) {
    position = (Vector2){x, y};
    health = 10;
    maxHealth = 10;
    speed = 5.f;
}

void Player::move() {
    if (IsKeyDown(KEY_W)) {
        position.y -= speed;
    } 
    if (IsKeyDown(KEY_S)) {
        position.y += speed;
    }
    if (IsKeyDown(KEY_A)) {
        position.x -= speed;
    }
    if (IsKeyDown(KEY_D)) {
        position.x += speed;
    }
}

void Player::levelUp() {
    level++;
    attack += 1;
    defense += 1;
    attackSpeed += 1;
    maxHealth += 5;
    health = maxHealth;
}

void Player::addItem(Item* item) {
    items.push_back(item);
    std::map<Modifier, int>::iterator it = item->modifiers.begin();
    while (it != item->modifiers.end()) {
        Modifier mod = it->first;
        switch (mod) {
            case (Health):
                maxHealth += it->second;
                break;                                                                                                                          
            case (Attack):
                attack += it->second;
                break;
            case (Defense):
                defense += it->second;
                break;
            case (AttackSpeed):
                attackSpeed += it->second;
                break;
            case (CritChance):
                critChance += ((it->second)/100);
                break;
            case (BlockChance):
                blockChance += ((it->second)/100);
                break;
        }
        it++;
    }
}
