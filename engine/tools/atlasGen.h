#ifndef ATLAS_GEN_H
#define ATLAS_GEN_H

#define _GNU_SOURCE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <dirent.h>
#include <math.h>
#include <png.h>
#include <sys/stat.h>

#include "../structs.h"
#include "../json/cJSON.h"

int main(int argc, char* argv[]);
static void handleCommandLine(int argc, char* argv[]);
static int initImages(void);
static int countImages(const char* dir);
static void loadImageData(int* i, const char* dir);
static int imageComparator(const void* a, const void* b);
static Node* findNode(Node* root, int w, int h);
static void splitNode(Node* node, int w, int h);
static void blitRotated(SDL_Surface* src, SDL_Surface* dest, int destx, int desty);
static int getPixel(SDL_Surface* surface, int x, int y);
static void putPixel(int x, int y, Uint32 pixel, SDL_Surface* dest);

#endif