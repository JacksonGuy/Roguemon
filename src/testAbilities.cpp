#include "testAbilities.h"
#include <iostream>

#include "Bleed.h"

void test1(Creature& user, Creature& target) {
    target.health -= user.attack;
}

void test2(Creature& user, Creature& target) {
    Bleed* bleed = new Bleed("Bleed", &target, 3, 1);
    target.harmEffects.push_back(bleed);
}

void test3(Creature& user, Creature& target) {
    std::cout << "Hell yeah" << std::endl;
}

void test4(Creature& user, Creature& target) {
    std::cout << "Not a pokemon clone" << std::endl;
}
