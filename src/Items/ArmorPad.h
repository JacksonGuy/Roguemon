#ifndef ARMORPAD_H
#define ARMORPAD_H

#include "../Item.h"

class ArmorPad : public Item {
    public:
        ArmorPad();
        ArmorPad(ArmorPad* ref);
        void effect();
};

#endif
