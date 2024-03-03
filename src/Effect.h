#ifndef EFFECT_H
#define EFFECT_H

#include "Creature.h"

class Effect {
    int duration;
    virtual void active(Creature& target);
    virtual void deactive(Creature& target);
};

#endif