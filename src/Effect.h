#ifndef EFFECT_H
#define EFFECT_H

#include <string>
class Creature;

class Effect {
    public:
        std::string name;
        int id;
        int duration = 1;
        virtual void active(Creature& target) = 0;
        virtual void effect(Creature& target) = 0; 
        virtual void deactive(Creature& target) = 0;
};

#endif