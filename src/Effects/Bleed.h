#ifndef BLEED_H
#define BLEED_H

#include "../Effect.h"

class Bleed : public Effect {
    public:
        int damage;

        Bleed(std::string name, Creature* target, int duration, int damage);
        void effect();
        ~Bleed();
};

#endif
