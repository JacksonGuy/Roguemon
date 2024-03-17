#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "../Item.h"

class HealthPotion : public Item {
    public:
        HealthPotion();
        HealthPotion(HealthPotion* ref);
        void effect();
};

#endif
