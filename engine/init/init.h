#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../definitions.h"
#include "../structs.h"
#include "../common.h"

#include "../sounds/sound.h"

extern App app;

extern AudioClip playerSnd;

void init(void);

void quit(void);

#endif