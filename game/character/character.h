#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/draw/2d.h"
#include "../../engine/sprites/spriteSlicer.h"
#include "../../engine/structs.h"

Character* constructCharacter(vec2* position);
void drawSurfaces(Character* player);
void deconstructCharacter(Character* player);

#endif