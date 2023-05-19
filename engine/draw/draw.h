#ifndef DRAW_H
#define DRAW_H

#include "../init/init.h"
#include "../inputs/input.h"
#include "../definitions.h"
#include "../structs.h"

void prepareScene(void);

void presentScene(void);

void blit(SDL_Surface* surf, int x, int y);

void blitRect(SDL_Surface* surf, SDL_Rect src, int x, int y);

SDL_Surface* loadImage(char* filename);

SDL_Surface* getSurface(char* name);

void addSurfaceToCache(char* name, SDL_Surface* sdlSurface);

#endif