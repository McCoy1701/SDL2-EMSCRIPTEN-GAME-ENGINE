#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "../engine/init/init.h"
#include "../engine/draw/draw.h"
#include "../engine/sounds/sound.h"
#include "../engine/text/text.h"
#include "../engine/inputs/input.h"
#include "../engine/utils/deltaTime.h"
#include "../engine/animations/animation.h"

#include "character/character.h"

#include "world/world.h"

extern Cell** MAP;
extern Character* player;

void gameLoop(void);

void initGame(void);

void doLoop(void);

void renderLoop(void);

void quitGame(void);

#endif