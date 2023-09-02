#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/utils/vector/vector.h"
#include "../../engine/sprites/spriteSlicer.h"
#include "../../engine/animations/animation.h"
#include "../../engine/structs.h"


Entity* entityConstructor(vec2* position, const char* filename);
AnimationNode* entityAnimationsConstructor(const char* filename);
void drawSurfaces(Entity* entity);
void entityDeconstructor(Entity* entity);

#endif