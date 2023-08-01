#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "../definitions.h"
#include "../structs.h"
#include "../utils/vector/vector.h"

#include "../sounds/sound.h"
#include "../text/text.h"

extern App app;
extern Stage stage;

extern AudioClip playerSnd;

void init(void);

void quit(void);

#endif