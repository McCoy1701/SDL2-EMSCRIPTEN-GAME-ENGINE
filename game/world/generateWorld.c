#include "world.h"


Cell** allocateWorldMemory(void) {
    Cell** grid = malloc(MAP_HEIGHT * sizeof(Cell*));
    for (int y = 0; y < MAP_HEIGHT; y++) {
        grid[y] = malloc(MAP_WIDTH * sizeof(Cell));
    }
    
    return grid;
}

void generateWorld(Cell** grid) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            // grid[i][j].x = (j - i) * (CELL_SIZE/2);
            // grid[i][j].y = (j + i) * (CELL_SIZE/2);
            // cartesianToIsometric(&grid[i][j].x, &grid[i][j].y, j, i);
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].w = CELL_SIZE;
            grid[i][j].h = CELL_SIZE;
            grid[i][j].hovering = 0;
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
    SDL_Rect temp;
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            temp.x = grid[i][j].x * CELL_SIZE;
            temp.y = grid[i][j].y * CELL_SIZE;
            temp.w = grid[i][j].w;
            temp.h = grid[i][j].h;

            // temp.y = (temp.y - (temp.h / 2));
            drawRect(&temp, grid[i][j].hovering);
        }
    }
}

void quitWorld(Cell** grid) {
    for (int i = 0; i < (MAP_HEIGHT); i++) {
        free(grid[i]);
    }
    free(grid);
}
