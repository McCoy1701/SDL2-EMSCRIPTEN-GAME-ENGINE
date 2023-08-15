#ifndef SPRITE_SLICER_H
#define SPRITE_SLICER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../draw/draw.h"
#include "../utils/vector/vector.h"
#include "../animations/animation.h"

SDL_Surface** sliceSpriteSheet(const char* filename, int x, int y, int frameCount);

#endif