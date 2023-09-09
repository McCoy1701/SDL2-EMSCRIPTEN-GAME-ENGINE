#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<string.h>

#include "uiStructs.h"

Button* buttonConstructor(float x, float y, const char* text, SDL_Surface* surf);

void isHovering(Button* button);

void isPressed(Button* button);

#endif