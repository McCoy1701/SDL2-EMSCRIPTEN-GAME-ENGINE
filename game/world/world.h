#ifndef WORLD_H
#define WORLD_H

#include <stdio.h>
#include <stdlib.h>

#include "../globals/global.h"
#include "../tiles/tiles.h"

#include "../../engine/definitions.h"
#include "../../engine/draw/draw.h"
#include "worldStruct.h"

extern Cell MAP[MAP_WIDTH][MAP_HEIGHT];

Cell** allocateWorldMemory(void);

void generateWorld(void);

void updateWorld(Cell** grid);

void displayWorld(Cell grid[MAP_WIDTH][MAP_HEIGHT]);

#endif