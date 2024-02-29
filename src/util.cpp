#include <cmath>
#include <string>
#include "raylib.h"
#include "Creature.h"

Texture2D SetTexture(std::string path) {
    Image texImage = LoadImage(path.c_str());
    ImageResize(&texImage, 64, 64); // TODO change this
    Texture2D texture = LoadTextureFromImage(texImage);
    UnloadImage(texImage);
    return texture;
}

float getDist(Creature c1, Creature c2) {
    return sqrt( pow(c2.position.y - c1.position.y, 2) + pow(c2.position.x - c1.position.x, 2)); 
}