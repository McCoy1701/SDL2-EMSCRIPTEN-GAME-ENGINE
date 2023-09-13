#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "globals/global.h"

#include "world/world.h"

extern Cell** MAP;
extern Entity* player;

void gameLoop(void);

void initGame(void);

void doLoop(void);

void renderLoop(void);

void quitGame(void);

#endif