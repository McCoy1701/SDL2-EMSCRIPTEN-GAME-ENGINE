#include "spriteSlicer.h"

SDL_Surface** sliceSpriteSheet(const char* filename, vec2* cellSize, int imageCount) {
    SDL_Surface** imageArray = malloc(sizeof(SDL_Surface) * imageCount);

    SDL_Surface* spriteSheet = IMG_Load(filename);

    if (!spriteSheet) {
        printf("[Error] sprite sheet not found %s | %s\n", filename, IMG_GetError());
        return NULL;
    }

    int spriteIndex = 0;

    for (int i = 0; i < imageCount; i++) {
        SDL_Rect sprite = createRect(i * cellSize->x, 0, cellSize->x, cellSize->y);

        imageArray[spriteIndex] = SDL_CreateRGBSurface(0, cellSize->x, cellSize->y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

        SDL_BlitSurface(spriteSheet, &sprite, imageArray[spriteIndex], NULL);
        
        spriteIndex++;
    }

    return imageArray;

}
