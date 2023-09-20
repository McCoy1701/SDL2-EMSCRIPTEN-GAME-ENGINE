#include "world.h"

static int i;

static int gridPage;

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

void testDisplay(void) {

    blitAtlasImage(blocksArray[i],      100, 100, 0);
    blitAtlasImage(concreteArray[i],    132, 100, 0);
    blitAtlasImage(decorationsArray[i], 164, 100, 0);
    blitAtlasImage(entitiesArray[i],    196, 100, 0);
    blitAtlasImage(fenceArray[i],       228, 100, 0);
    blitAtlasImage(glassArray[i],       250, 100, 0);
    blitAtlasImage(grassArray[i],       282, 100, 0);
    blitAtlasImage(oreArray[i],         312, 100, 0);
    blitAtlasImage(plantsArray[i],      344, 100, 0);
    blitAtlasImage(redstoneArray[i],    376, 100, 0);
    blitAtlasImage(slabsArray[i],       408, 100, 0);
    blitAtlasImage(stairsArray[i],      440, 100, 0);
    blitAtlasImage(stoneArray[i],       472, 100, 0);
    blitAtlasImage(terracottaArray[i],  504, 100, 0);
    blitAtlasImage(wallArray[i],        536, 100, 0);
    blitAtlasImage(woodArray[i],        568, 100, 0);
    blitAtlasImage(woolArray[i],        600, 100, 0);
    i++;
    sleep(1);
    
    
    printf("index: %d\n", i);
    
    if (i > 128) {
        i = 0;
        printf("reset: %d\n", i);
    }
}

void drawGrid(AtlasImage* atlasImage[NUM_OF_BLOCKS], int x, int y, int w, int h) {
    for (int k = 0; k < w; k++) {
        for (int j = 0; j < h; j++) {
            blitAtlasImage(atlasImage[i], x + k * 24, y + j * 24, 0);
            i++;
            if (i >= w * h) {
                i = 0;
            }
        }
    }
}

void drawGrids(Button* backButton, Button* forwardButton, int x, int y) {
    if (forwardButton->clicked) {
        gridPage++;
    }

    if (backButton->clicked) {
        gridPage--;
    }

    switch (gridPage) {
        case blocks:
            drawGrid(blocksArray, x, y, 16, 16);
            break;

        case concrete:
            drawGrid(concreteArray, x, y, 16, 16);
            break;

        case decorations:
            drawGrid(decorationsArray, x, y, 16, 16);
            break;

        case entities:
            drawGrid(entitiesArray, x, y, 16, 16);
            break;

        case fence:
            drawGrid(fenceArray, x, y, 16, 16);
            break;

        case glass:
            drawGrid(glassArray, x, y, 16, 16);
            break;

        case grass:
            drawGrid(grassArray, x, y, 16, 16);
            break;

        case ore:
            drawGrid(oreArray, x, y, 16, 16);
            break;

        case plants:
            drawGrid(plantsArray, x, y, 16, 16);
            break;

        case redstone:
            drawGrid(redstoneArray, x, y, 16, 16);
            break;

        case slabs:
            drawGrid(slabsArray, x, y, 16, 16);
            break;

        case stairs:
            drawGrid(stairsArray, x, y, 16, 16);
            break;

        case stone:
            drawGrid(stoneArray, x, y, 16, 16);
            break;

        case terracotta:
            drawGrid(terracottaArray, x, y, 16, 16);
            break;

        case wall:
            drawGrid(wallArray, x, y, 16, 16);
            break;

        case wood:
            drawGrid(woodArray, x, y, 16, 16);
            break;

        case wool:
            drawGrid(woolArray, x, y, 16, 16);
            break;

        default: 
            break;
        }
}

