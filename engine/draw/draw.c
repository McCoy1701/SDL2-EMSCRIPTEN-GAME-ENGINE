#include "draw.h"

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}

void blit(SDL_Surface* surf, int x, int y) {
    SDL_Rect dest;
    SDL_Texture* img;

    dest.x = x;
    dest.y = y;

    img = SDL_CreateTextureFromSurface(app.renderer, surf);

    int success = SDL_QueryTexture(img, NULL, NULL, &dest.w, &dest.h);

    if (success < 0) {
        printf("Error creating texture %s\n", SDL_GetError());
    }

    SDL_RenderCopy(app.renderer, img, NULL, &dest);
}

void blitRect(SDL_Surface* surf, SDL_Rect src, int x, int y) {
    SDL_Rect dest;
    SDL_Texture* img;

    dest.x = x;
    dest.y = y;
    dest.w = src.w;
    dest.h = src.h;

    img = SDL_CreateTextureFromSurface(app.renderer, surf);

    int success = SDL_QueryTexture(img, NULL, NULL, &dest.w, &dest.h);

    if (success < 0) {
        printf("Error creating texture %s\n", SDL_GetError());
    }

    SDL_RenderCopy(app.renderer, img, &src, &dest);
}

SDL_Surface* loadImage(char* filename) {
    SDL_Surface* surface;

    surface = getSurface(filename);
    
    if (surface == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        surface = IMG_Load(filename);
        addSurfaceToCache(filename, surface);
    }

    return surface;
}

SDL_Surface* getSurface(char* name) {
   Surface* surf;

    for (surf = app.surfaceHead.next; surf != NULL; surf = surf->next) {
        if (strcmp(surf->name, name) == 0) {
        return surf->surface;
        printf("%s", surf->name);
        }
    }

    return NULL;
}

void addSurfaceToCache(char* name, SDL_Surface* sdlSurface) {
    Surface* surface;

    surface = malloc(sizeof(Surface));
    memset(surface, 0, sizeof(Surface));

    app.surfaceTail = surface;
    app.surfaceTail->next = surface;

    STRNCPY(surface->name, name, MAX_NAME_LENGTH);
    surface->surface = sdlSurface;
}
