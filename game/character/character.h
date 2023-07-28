#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/draw/2d.h"
#include "../../engine/sprites/spriteSlicer.h"
#include "../../engine/structs.h"

typedef struct _character {
    vec2* position;
    vec2* velocity;
    AnimationNode* animations;
} Character;

Character* constructCharacter(vec2* position);
AnimationNode* constructCharacterAnimations(const char* filename);
void drawSurfaces(Character* player);
void deconstructCharacter(Character* player);

#endif