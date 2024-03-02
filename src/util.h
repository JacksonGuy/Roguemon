#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "raylib.h"
#include "Creature.h"

Texture2D SetTexture(std::string, int, int);
float getDist(Vector2, Vector2);

#endif