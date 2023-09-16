#include "world.h"


Cell MAP[MAP_WIDTH][MAP_HEIGHT];

Cell** allocateWorldMemory(void) {
    Cell** grid = malloc(MAP_HEIGHT * sizeof(Cell*));
    for (int y = 0; y < MAP_HEIGHT; y++) {
        grid[y] = malloc(MAP_WIDTH * sizeof(Cell));
    }
    
    return grid;
}

void generateWorld(void) {
    
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            // printf("count: %d\n", tileCount);
            MAP[x][x].id = (rand() % tileCount);
            MAP[y][x].hovering = 0;
        }
    }

    printf("Generated World!\n");
}

void updateWorld(Cell** grid) {
    Mouse mouse;
    Uint32 buttonMask = SDL_GetGlobalMouseState(&(mouse.x), &(mouse.y));
    if (buttonMask & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        int gridx = mouse.x / CELL_SIZE;
        int gridy = mouse.y / CELL_SIZE;

        grid[gridy][gridx].hovering = 1;
        
        grid[gridy-1][gridx].hovering = 1;
        grid[gridy][gridx+1].hovering = 1;
        grid[gridy+1][gridx].hovering = 1;
        grid[gridy][gridx-1].hovering = 1;
    }

    if (buttonMask & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        int gridx = mouse.x / CELL_SIZE;
        int gridy = mouse.y / CELL_SIZE;

        grid[gridy][gridx].hovering = 0;

        grid[gridy-1][gridx-1].hovering = 0;
        grid[gridy+1][gridx-1].hovering = 0;
        grid[gridy+1][gridx+1].hovering = 0;
        grid[gridy-1][gridx+1].hovering = 0;
    }
}

void displayWorld(Cell** grid) {
    int sx, sy;
    for (int x = MAP_WIDTH; x > 0; x--) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            toISO(x, y, &sx, &sy);
            // printf("X,Y: %d, %d\n", sx, sy);
            blitAtlasImage(blocks[grid[y][x].id], sx, sy, 0);
        }
    }
}

