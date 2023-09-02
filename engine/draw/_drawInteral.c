#include "draw.h"

SDL_Surface* loadImage(char* filename) {
    SDL_Surface* surface;

    surface = getSurface(filename);
    
    if (surface == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        surface = IMG_Load(filename);
        if (surface == NULL) {
            printf("Error loading %s , %s", filename, SDL_GetError());
        }
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
