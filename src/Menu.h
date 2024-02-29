#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include <string>
#include <vector>

#include "Button.h"

class Menu {
    public:
        Vector2 position;
        Texture2D background;
        
        std::vector<std::string> textOptions;
        std::vector<Button> buttons;

        void Draw();
        int checkButtons();
};

#endif