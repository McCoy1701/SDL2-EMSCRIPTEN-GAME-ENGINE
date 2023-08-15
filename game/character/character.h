#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/utils/vector/vector.h"
#include "../../engine/sprites/spriteSlicer.h"
#include "../../engine/animations/animation.h"
#include "../../engine/structs.h"


Entity* constructEntity(vec2* position, const char* filename);
AnimationNode* constructEntityAnimations(const char* filename);
void drawSurfaces(Entity* entity);
void deconstructEntity(Entity* entity);

#endif