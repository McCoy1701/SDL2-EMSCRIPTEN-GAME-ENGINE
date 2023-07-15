#include "draw.h"

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    SDL_RenderClear(app.renderer);
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
    doInput();
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}

void drawPoint(int x, int y) {
    SDL_RenderDrawPoint(app.renderer, x, y);
}

void drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(app.renderer, x1, y1, x2, y2);
}

void drawHoriLine(int x1, int x2, int y) {
    SDL_RenderDrawLine(app.renderer, x1, y, x2, y);
}

void drawVertLine(int y1, int y2, int x) {
    SDL_RenderDrawLine(app.renderer, x, y1, x, y2);
}

void drawRect(SDL_Rect* src, int value) {
    if (!value) {
        SDL_RenderDrawRect(app.renderer, src);
    }

    else {
        SDL_RenderFillRect(app.renderer, src);
    }
}

void drawIsoRect(SDL_Rect* src, int value) {
    SDL_RenderDrawLine(app.renderer, src->x, src->y, (src->x + src->w), (src->y - src->h));
    SDL_RenderDrawLine(app.renderer, (src->x + src->w), (src->y - src->h), (src->x + (src->w * 2)), src->y);
    SDL_RenderDrawLine(app.renderer, (src->x + (src->w * 2)), src->y, (src->x + src->w), (src->y + src->h));
    SDL_RenderDrawLine(app.renderer, (src->x + src->w), (src->y + src->h), src->x, src->y);    
    
    if (value) {
        for (int i = src->y + 1; i < (src->y + (src->h / 2)); i++){
            for (int j = src->x + 1; i < (src->x + (src->w / 2)); j++) {
                SDL_RenderDrawLine(app.renderer, i, j, i + src->w / 2, j);
            }
        }
    }
}

void drawCircle(int x, int y, int radius) {
   int centerX;
   int centerY;

   for (int i = 0; i < 360; i++)  {
    centerX = x + radius * cos(i);
    centerY = y + radius * sin(i);
    SDL_RenderDrawPoint(app.renderer, centerX, centerY);
   }
}

SDL_Rect createRect(int x, int y, int w, int h) {
    SDL_Rect temp;
    temp.x = x;
    temp.y = y;
    temp.w = w;
    temp.h = h;
    return temp;
}

void blit(SDL_Surface* surf, int x, int y) {
    SDL_Rect dest;
    SDL_Texture* img;

    dest.x = x;
    dest.y = y;

    img = SDL_CreateTextureFromSurface(app.renderer, surf);

    SDL_FreeSurface(surf);
    
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

    SDL_FreeSurface(surf);

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

void cartesianToIsometric(int* isoX, int* isoY, int cartX, int cartY) {
    *isoX = (cartX - cartY) * (CELL_SIZE/2);
    *isoY = (cartX + cartY) * (CELL_SIZE/2);
}
