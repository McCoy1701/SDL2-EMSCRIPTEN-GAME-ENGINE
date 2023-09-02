#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/utils/vector/vector.h"
#include "../../engine/animations/animation.h"
#include "../../engine/structs.h"


AnimationNode* entityAnimationsConstructor(const char* filename);
void drawSurfaces(Entity* entity);

#endif