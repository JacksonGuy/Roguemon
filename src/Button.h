#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <string>

class Button {
    public:
        Vector2 position;
        Rectangle rect;
        std::string text;
        int size = 20;
        Color color = WHITE;

        Button(Vector2, std::string);
        void GetRect();
        void Draw();
};

#endif