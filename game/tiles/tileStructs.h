#ifndef TILE_STRUCTS_H
#define TILE_STRUCTS_H

#include "../../engine/utils/vector/vector.h"
#include "tileEnums.h"

typedef struct _tile {
    vec3 position;
    vec2 screenPosition;
    
    ResourceType material;
    GemType gem;
    EconomicType stone;
    MetalType ore;
    WoodType log;
    OtherType other;

    int health;
    int hardness;
    int spriteId;
} Tile;

#endif