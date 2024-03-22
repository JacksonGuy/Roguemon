#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "raylib.h"
#include "Creature.h"

Texture2D* SetTexture(std::string path, int width, int height);
float getDist(Vector2, Vector2);

#endif