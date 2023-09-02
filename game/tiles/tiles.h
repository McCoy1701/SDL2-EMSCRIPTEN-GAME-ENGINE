#ifndef TILES_H
#define TILES_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "tileStructs.h"

#define NUM_OF_TILES 128

extern SDL_Surface* tileCache[NUM_OF_TILES];

Tile* tileConstructor(vec3 position, ResourceType material, 
GemType gem, EconomicType stone, MetalType ore,
WoodType log, OtherType other);

void tileDeconstructor(Tile* tile);

#endif