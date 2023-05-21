#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../structs.h"

Animation* createAnimation(int numFrames, uint32_t msPerFrame);

void destroyAnimation(Animation* animation);

int loadFrames(Animation* animation, SDL_Renderer* renderer, char* filename);

#endif