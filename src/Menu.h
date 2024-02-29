#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include <string>
#include <vector>

#include "Button.h"
#include "MenuText.h"

class Menu {
    public:
        Vector2 position;
        Texture2D background;
        int width;
        int height;

        std::vector<MenuText> textOptions;
        std::vector<Button> buttons;

        void Draw();
        int checkButtons();
};

#endif
