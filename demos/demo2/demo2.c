#include "demo2.h"

void initDemo(void) {
    int i;
    char filename[MAX_FILENAME_LENGTH];

    sphereAtlasImages[0] = getAtlasImage("gfx/spheres/blue.png");
    sphereAtlasImages[1] = getAtlasImage("gfx/spheres/lime.png");
    sphereAtlasImages[3] = getAtlasImage("gfx/spheres/orange.png");
    sphereAtlasImages[2] = getAtlasImage("gfx/spheres/purple.png");
    sphereAtlasImages[4] = getAtlasImage("gfx/spheres/red.png");

    for (i = 0; i < NUM_SPHERES; i++) {
        spheres[i].x =  rand() % SCREEN_WIDTH;
        spheres[i].y = 50 + (rand() % (SCREEN_HEIGHT - 100));
    }

    blocksAtlasImages[0] = getAtlasImage("gfx/cubes/bigGreen.png");
    blocksAtlasImages[1] = getAtlasImage("gfx/cubes/bigGrey.png");
    blocksAtlasImages[2] = getAtlasImage("gfx/cubes/bigRed.png");

    for (i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].x = rand() % (MAP_SIZE - 4);
        blocks[i].y = rand() % (MAP_SIZE - 4);
    }

    qsort(blocks, sizeof(SDL_Point), NUM_BLOCKS, blockComparator);

    for (i = 0; i < NUM_TILES; i++) {
        sprintf(filename, "gfx/tiles/%d.png", i + 1);
        tilesAtlasImages[i] = getAtlasImage(filename);
    }

    for (i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
        map[i] = rand() % NUM_TILES;
    }

    app.delegate.logic = logic;
    app.delegate.draw = draw;
}

void logic(void) {
    doSpheres();
}

void doSpheres(void) {
    int i;

    for (i = 0; i < NUM_SPHERES; i++) {
        spheres[i].x += 4;

        if (spheres[i].x >= (SCREEN_WIDTH + sphereAtlasImages[i]->rect.w)) {
            spheres[i].x = -sphereAtlasImages[i]->rect.w;
        }
    }
}

void draw(void) {
    drawTiles();

    drawBlocks();

    drawSpheres();
}

void drawSpheres(void) {
    int i;

    for (i = 0; i < NUM_SPHERES; i++) {
        blitAtlasImage(sphereAtlasImages[i], spheres[i].x, spheres[i].y, 1);
    }
}

void drawTiles(void) {
    int y, x, sx, sy, i;
    i = 0;

    for (x = MAP_SIZE; x > 0; x--) {
        for (y = 0; y < MAP_SIZE; y++) {
            toISO(x, y, &sx, &sy);

            blitAtlasImage(tilesAtlasImages[map[i]], sx, sy, 0);

            i++;
        }
    }
}

void drawBlocks(void) {
    int sx, sy, i;

    for (i = 0; i < NUM_BLOCKS; i++) {
        toISO(blocks[i].x, blocks[i].y, &sx, &sy);
        blitAtlasImage(blocksAtlasImages[i % NUM_BLOCK_IMAGES], sx, sy, 0);
    }
}


int blockComparator(const void* a, const void* b) {
    SDL_Point* p1 = (SDL_Point*)a;
    SDL_Point* p2 = (SDL_Point*)b;

    return p1->y - p2->y;
}
