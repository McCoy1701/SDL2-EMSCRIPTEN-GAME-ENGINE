#include "spriteSlicer.h"

SDL_Surface** sliceSpriteSheet(const char* filename, int x, int y, int frameCount) {
    SDL_Surface** imageArray = (SDL_Surface**)malloc(frameCount * sizeof(SDL_Surface*));
    memset(imageArray, 0, frameCount * sizeof(SDL_Surface*));

    printf("what is the filename %s\n", filename);
    SDL_Surface* spriteSheet = IMG_Load(filename);

    if (!spriteSheet) {
        printf("[Error] sprite sheet not found %s | %s\n", filename, IMG_GetError());
        return NULL;
    }

    int spriteIndex = 0;

    for (int i = 0; i < frameCount; i++) {
        SDL_Rect sprite = createRect(i * x, 0, x, y);

        imageArray[spriteIndex] = SDL_CreateRGBSurface(0, x, y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

        SDL_BlitSurface(spriteSheet, &sprite, imageArray[spriteIndex], NULL);
        
        spriteIndex++;
    }

    return imageArray;

}
