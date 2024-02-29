#include "Menu.h"

void Menu::Draw() {
    DrawTexture(this->background, this->position.x, this->position.y, WHITE);
    for (Button button : this->buttons) {
        button.Draw();
    }
}

int Menu::checkButtons() {
    Vector2 mpos = GetMousePosition();
    for (Button button : this->buttons) {
        // Get absolute position of button
        // Remember: button position is relative to menu
        Vector2 buttonPos = (Vector2){this->position.x + button.position.x, 
                                this->position.y + button.position.y};
        
        // Is the mouse within the button's boundary?
        if ((mpos.x >= buttonPos.x && mpos.x <= buttonPos.x + button.width)
            && (mpos.y <= buttonPos.y && mpos.y >= buttonPos.y + button.height)) {
                if (IsMouseButtonPressed(1)) {
                    return button.id;
                }
            }
    }
}