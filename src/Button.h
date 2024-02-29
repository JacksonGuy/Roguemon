#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <string>

class Button {
    public:
        int id;
        Vector2 position;
        Texture2D background;
        int width;
        int height;
        std::string text;

        void Draw();
};

#endif