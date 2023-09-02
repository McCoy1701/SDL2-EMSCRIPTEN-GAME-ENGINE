#ifndef DEMO_H
#define DEMO_H

#include "../engine/utils/utils.h"

#include "../engine/atlas/atlas.h"
#include "../engine/draw/draw.h"

#include "../engine/init/init.h"

#define NUM_SPHERES 5

extern App app;

static void logic(void);
static void draw(void);
void drawTiles(void);
void drawTallSpinner(void);
void drawAlphaSpheres(void);
void drawColoredCube(void);
void drawScaledSprites(void);

AtlasImage* sphereAtlasImages[NUM_SPHERES];
AtlasImage* tiles[2];
AtlasImage* cube;
AtlasImage* tallAtlasImage;

void initDemo(void);

#endif