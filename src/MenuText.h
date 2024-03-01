#ifndef MENUTEXT_H
#define MENUTEXT_H

#include <string>
#include "raylib.h"

class MenuText {
    public:
        std::string text;
        Vector2 position;
        int size;
        Color color;

        void Draw();
};

#endif
