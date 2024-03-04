#ifndef BLEED_H
#define BLEED_H

#include "Effect.h"

class Bleed : public Effect {
    public:
        int damage;

        Bleed(std::string name, int duration, int damage);
        void active(Creature& target);
        void effect(Creature& target);
        void deactive(Creature& target);
};

#endif