#ifndef WORLD_H
#define WORLD_H

#include "../../engine/definitions.h"
#include "../../engine/draw/draw.h"
#include "worldStruct.h"

Cell** allocateWorldMemory(void);

void generateWorld(Cell** grid);

void updateWorld(Cell** grid);

void displayWorld(Cell** grid);

void quitWorld(Cell** grid);

#endif