#ifndef ATLAS_H
#define ATLAS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../json/cJSON.h"

#include "../utils/utils.h"
#include "../init/init.h"

void loadAtlasData(void);

void initAtlas(void);

AtlasImage* getAtlasImage(char* filename);

void loadAtlasData(void);

void setAtlasColor(int r, int g, int b, int a);

#endif