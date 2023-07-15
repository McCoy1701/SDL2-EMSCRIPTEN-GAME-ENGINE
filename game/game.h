#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "../engine/init/init.h"
#include "../engine/draw/draw.h"
#include "../engine/sounds/sound.h"
#include "../engine/text/text.h"
#include "../engine/inputs/input.h"

#include "world/world.h"

extern Cell** MAP;

void gameLoop(void);

void initGame(void);

void doLoop(void);

void renderLoop(void);

void quitGame(void);

#endif