#include <cmath>
#include <string>
#include "raylib.h"
#include "Creature.h"

Texture2D SetTexture(std::string path, int width, int height) {
    Image texImage = LoadImage(path.c_str());
    ImageResize(&texImage, width, height);
    Texture2D texture = LoadTextureFromImage(texImage);
    UnloadImage(texImage);
    return texture;
}

float getDist(Vector2 c1, Vector2 c2) {
    return sqrt( pow(c2.y - c1.y, 2) + pow(c2.x - c1.x, 2) ); 
}