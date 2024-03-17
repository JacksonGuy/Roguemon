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

void Player::addInventory(Item* item) {
    inventory.push_back(item);
    // TODO inventory restrictions? 
}

void Player::removeInventory(Item* item) {
    for (int i = 0; i < inventory.size(); i++) {
        Item* invItem = inventory[i];
        if (invItem == item) {
            inventory.erase(inventory.begin() + i);
            free(invItem);
            break;
        }
    }
}

void Player::addItem(Item* item) {
    items.push_back(item);
    
    // TODO this could maybe be done better
    // we should probably take more advantage of
    // the effect function on items and place
    // this code inside of there.
    // That way it is more versatile and more organized for
    // future items.
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
