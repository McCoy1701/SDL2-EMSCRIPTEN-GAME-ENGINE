#ifndef TILE_ENUMS_H
#define TILE_ENUMS_H

typedef enum _tileTypes {
    TILE_STONE,
    TILE_GRASS,
    TILE_CONSTRUCTION,
    TILE_ORE,
    TILE_GEM,
    TILE_WOOD,
    TILE_OTHER,
} TileTypes;

typedef enum _resourceType {
    METAL,
    ECONOMIC,
    GEM,
    WOOD,
    OTHER,
} ResourceType;

typedef enum _gemType {
    diamond,
    emerald,
    ruby,
    shappire,
    onxy,
} GemType;

typedef enum _economicType {
    jet,
    grabbo,
    microline,
    granite,
    diroite,
    pitchblend,
} EconomicType;

typedef enum _metalType {
    magnetite,
    hematite,
    malachite,
    chalcocite,
    chalcopyrite,
    bornite,
    limonite,
    galena,
    tetrahedrite,
    chlorargyrite,
    cassiterite,
    gold_nuggets,
    platinum_nuggets,
    silver_nuggets,
    copper_nuggets,
} MetalType;

typedef enum _woodType {
    oak,
    ash,
    maple,
    walnut,
    black_walnut,
    birch,
    baltic_birch,
} WoodType;

typedef enum _otherType {
    clay,
} OtherType;

typedef enum _waterDirection {
    north,
    northEast,
    east,
    southEast,
    south,
    southWest,
    west,
    northWest,
    down,
} WaterDirection;

#endif