#include "world.h"


Cell MAP[MAP_WIDTH][MAP_HEIGHT];

void generateWorld(void) {
    
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            MAP[x][y].type = (Types)(rand() % TYPE_COUNT);
            MAP[x][y].hovering = 0;
            // printf("type: %d\n", MAP[x][y].type);
        }
    }

    printf("Generated World!\n");
}


