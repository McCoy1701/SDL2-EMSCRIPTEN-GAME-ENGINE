#include "../engine/utils/utils.h"
#include "../engine/atlas/atlas.h"
#include "../engine/draw/draw.h"
#include "../engine/init/init.h"

#define NUM_SPHERES      5
#define NUM_TILES        11
#define TILE_WIDTH       42
#define TILE_HEIGHT      20
#define MAP_OFFSET_X    -70
#define MAP_OFFSET_Y     350
#define NUM_BLOCK_IMAGES 3
#define NUM_BLOCKS       12
#define MAP_SIZE         35

extern App app;

void logic(void);
void draw(void);
void doSpheres(void);
void drawSpheres(void);
void drawTiles(void);
void drawBlocks(void);
int blockComparator(const void* a, const void* b);

AtlasImage* sphereAtlasImages[NUM_SPHERES];
AtlasImage* tilesAtlasImages[NUM_TILES];
AtlasImage* blocksAtlasImages[NUM_BLOCK_IMAGES];
SDL_Point spheres[NUM_SPHERES];
SDL_Point blocks[NUM_BLOCKS];
int map[MAP_SIZE * MAP_SIZE];

void initDemo(void);