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

void displayWorld(Cell grid[MAP_WIDTH][MAP_HEIGHT]) {
    int sx, sy;
    for (int x = MAP_WIDTH; x > 0; x--) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            toISO(x, y, &sx, &sy);
            // printf("X,Y: %d, %d\n", sx, sy);

            switch (grid[x][y].type) {
            
            case blocks:
                blitAtlasImage(blocksArray[0], sx, sy, 0);
                break;
            
            case concrete:
                blitAtlasImage(concreteArray[0], sx, sy, 0);
                break;
            
            case decorations:
                blitAtlasImage(decorationsArray[0], sx, sy, 0);
                break;
            
            case entities:
                blitAtlasImage(entitiesArray[0], sx, sy, 0);
                break;
            
            case fence:
                blitAtlasImage(fenceArray[0], sx, sy, 0);
                break;
            
            case glass:
                blitAtlasImage(glassArray[0], sx, sy, 0);
                break;
            
            case grass:
                blitAtlasImage(grassArray[0], sx, sy, 0);
                break;
            
            case ore:
                blitAtlasImage(oreArray[0], sx, sy, 0);
                break;
            
            case plants:
                blitAtlasImage(plantsArray[0], sx, sy, 0);
                break;
            
            case redstone:
                blitAtlasImage(redstoneArray[0], sx, sy, 0);
                break;
            
            case slabs:
                blitAtlasImage(slabsArray[0], sx, sy, 0);
                break;
            
            case stairs:
                blitAtlasImage(stairsArray[0], sx, sy, 0);
                break;
            
            case stone:
                blitAtlasImage(stoneArray[0], sx, sy, 0);
                break;
            
            case terracotta:
                blitAtlasImage(terracottaArray[0], sx, sy, 0);
                break;
            
            case wall:
                blitAtlasImage(wallArray[0], sx, sy, 0);
                break;
            
            case wood:
                blitAtlasImage(woodArray[0], sx, sy, 0);
                break;
            
            case wool:
                blitAtlasImage(woolArray[0], sx, sy, 0);
                break;
            
            default:
                break;
            }
        }
    }
}

