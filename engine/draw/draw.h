#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include <unistd.h>

#include "../init/init.h"
#include "../inputs/input.h"
// #include "../definitions.h"
// #include "../structs.h"

void prepareScene(void);

void presentScene(void);

void drawPoint(int x, int y);

void drawLine(int x1, int y1, int x2, int y2);

void drawHoriLine(int x1, int x2, int y);

void drawVertLine(int y1, int y2, int x);

void drawCircle(int x, int y, int radius);

void drawRect(SDL_Rect* src, int value);

void drawIsoRect(SDL_Rect* src, int value);

SDL_Rect createRect(int x, int y, int w, int h);

void blit(SDL_Surface* surf, int x, int y);

void blitRect(SDL_Surface* surf, SDL_Rect src, int x, int y);

SDL_Surface* loadImage(char* filename);

SDL_Surface* getSurface(char* name);

void addSurfaceToCache(char* name, SDL_Surface* sdlSurface);

void cartesianToIsometric(int* isoX, int* isoY, int cartX, int cartY);

#endif