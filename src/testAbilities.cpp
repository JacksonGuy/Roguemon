#include "testAbilities.h"
#include <iostream>

void test1(Creature& user, Creature& target) {
    target.health -= user.attack;
    std::cout << "This works!" << std::endl;
}

void test2(Creature& user, Creature& target) {
    std::cout << "This Too!" << std::endl;
}

void test3(Creature& user, Creature& target) {
    std::cout << "Hell yeah" << std::endl;
}

void test4(Creature& user, Creature& target) {
    std::cout << "Not a pokemon clone" << std::endl;
}