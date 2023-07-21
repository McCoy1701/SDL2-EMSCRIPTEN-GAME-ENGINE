#ifndef SPRITE_SLICER_H
#define SPRITE_SLICER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../draw/2d.h"
#include "../draw/draw.h"

SDL_Surface** sliceSpriteSheet(const char* filename, vec2* cellSize, int imageCount);

#endif