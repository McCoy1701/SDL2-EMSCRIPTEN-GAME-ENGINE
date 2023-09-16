#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "globals/global.h"

#include "world/world.h"
#include "tiles/tiles.h"

extern Entity* player;

void gameLoop(void);

void initGame(void);

void doLoop(void);

void renderLoop(void);

void quitGame(void);

#endif