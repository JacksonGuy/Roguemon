#include "testAbilities.h"
#include <iostream>

#include "Bleed.h"

void test1(Creature& user, Creature& target) {
    target.health -= user.attack;
    std::cout << "Attack 1" << std::endl;
}

void test2(Creature& user, Creature& target) {
    Bleed bleed("Bleed", 3, 1);
    target.harmEffects.push_back(&bleed);
    std::cout << "Bleed ability passed" << std::endl;
}

void test3(Creature& user, Creature& target) {
    std::cout << "Hell yeah" << std::endl;
}

void test4(Creature& user, Creature& target) {
    std::cout << "Not a pokemon clone" << std::endl;
}