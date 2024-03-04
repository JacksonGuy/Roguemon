#ifndef EFFECT_H
#define EFFECT_H

#include <string>
class Creature;

class Effect {
    public:
        std::string name;
        int id;
        int duration;
        Creature* target;
        virtual void effect() = 0;
};

#endif
