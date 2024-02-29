#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "raylib.h"
#include "Creature.h"

Texture2D SetTexture(std::string);
float getDist(Creature, Creature);

#endif