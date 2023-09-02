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

    SDL_DestroyTexture(img);
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

void blitAtlasImage(AtlasImage* atlasImage, int x, int y, int center) {
    SDL_Rect dest;
    SDL_Point p;

    dest.x = x;
    dest.y = y;
    dest.w = atlasImage->rect.w;
    dest.h = atlasImage->rect.h;

    if (!atlasImage->rotated) {
        if (center) {
            dest.x -= (dest.w / 2);
            dest.y -= (dest.h / 2);
        }

        SDL_RenderCopy(app.renderer, atlasImage->texture, &atlasImage->rect, &dest);
    } 
    
    else {
        if (center) {
            dest.x -= (dest.w / 2);
            dest.y -= (dest.h / 2);
        }

        p.x = 0;
        p.y = 0;

        dest.y += atlasImage->rect.w;

        SDL_RenderCopyEx(app.renderer, atlasImage->texture, &atlasImage->rect, &dest, -90, &p, SDL_FLIP_NONE);
    }
}

void blitAtlasImageRotated(AtlasImage* atlasImage, int x, int y, int angle) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = atlasImage->rect.w;
    dest.h = atlasImage->rect.h;

    if (!atlasImage->rotated) {
        dest.x -= (atlasImage->rect.h / 2);
        dest.y -= (atlasImage->rect.w / 2);
        
    } else {
        dest.x -= (atlasImage->rect.h / 2);
        dest.y -= (atlasImage->rect.w / 2);

        angle -= 90;

    }
  
    SDL_RenderCopyEx(app.renderer, atlasImage->texture, &atlasImage->rect, &dest, angle, NULL, SDL_FLIP_NONE);
}

void blitAtlasImageScaled(AtlasImage* atlasImage, int x, int y, int w, int h) {
    SDL_Rect dest;
    SDL_Point p;

    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

    if (atlasImage->rotated) {
        p.x = 0;
        p.y = 0;

        dest.y += w;

        SDL_RenderCopyEx(app.renderer, atlasImage->texture, &atlasImage->rect, &dest, -90, &p, SDL_FLIP_NONE);
    } 
    
    else {
        SDL_RenderCopy(app.renderer, atlasImage->texture, &atlasImage->rect, &dest);
    }
}

void cartesianToIsometric(int* isoX, int* isoY, int cartX, int cartY) {
    *isoX = (cartX - cartY) * (CELL_SIZE/2);
    *isoY = (cartX + cartY) * (CELL_SIZE/2);
}
