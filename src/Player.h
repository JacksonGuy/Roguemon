#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
    private:
        int health;
        int maxHealth;
        Vector2 position;
        int speed;
        Texture2D texture;

    public:
        Player(int x, int y);
        
        void setPosition(Vector2);
        Vector2 getPosition();
        
        void setTexture(Texture2D&);
        Texture2D getTexture();
};

#endif