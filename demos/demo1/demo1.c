#include "demo1.h"

static int tallAngle;
static int tileAngle;

void initDemo(void) {
    int i;
    char filename[MAX_FILENAME_LENGTH];

    sphereAtlasImages[0] = getAtlasImage("gfx/spheres/smallRed.png");
    sphereAtlasImages[1] = getAtlasImage("gfx/spheres/smallGreen.png");
    sphereAtlasImages[2] = getAtlasImage("gfx/spheres/smallGrey.png");
    sphereAtlasImages[3] = getAtlasImage("gfx/spheres/smallCyan.png");

    cube = getAtlasImage("gfx/cubes/bigGrey.png");

    tiles[0] = getAtlasImage("gfx/tiles/1.png");
    tiles[1] = getAtlasImage("gfx/tiles/7.png");

    tallAtlasImage = getAtlasImage("gfx/tall/long.png");

    tallAngle = 0;
    tileAngle = 0;

    app.delegate.logic = logic;
    app.delegate.draw = draw;
}

static void logic(void) {
    tallAngle++;
    tileAngle++;
}

static void draw(void) {
    drawTiles();

    drawTallSpinner();

    drawAlphaSpheres();

    drawColoredCube();

    drawScaledSprites();
}

void drawTiles(void) {
    blitAtlasImage(tiles[0], 50, 50, 0);
    blitAtlasImage(tiles[1], 150, 50, 0);
    blitAtlasImageRotated(tiles[1], 250, 50 + (tiles[1]->rect.w / 2), tileAngle);
}

void drawTallSpinner(void) {
    blitAtlasImageRotated(tallAtlasImage, 150, 250, tallAngle);
    blitAtlasImageRotated(tallAtlasImage, 300, 250, tallAngle + 20);
    blitAtlasImageRotated(tallAtlasImage, 450, 250, tallAngle + 40);
    blitAtlasImageRotated(tallAtlasImage, 600, 250, tallAngle + 60);
    blitAtlasImageRotated(tallAtlasImage, 750, 250, tallAngle + 80);
}

void drawAlphaSpheres(void) {
    setAtlasColor(255, 255, 255, 255);
    blitAtlasImage(sphereAtlasImages[0], 50, 150, 0);

    setAtlasColor(255, 255, 255, 170);
    blitAtlasImage(sphereAtlasImages[1], 100, 150, 0);

    setAtlasColor(255, 255, 255, 100);
    blitAtlasImage(sphereAtlasImages[2], 150, 150, 0);

    setAtlasColor(255, 255, 255, 64);
    blitAtlasImage(sphereAtlasImages[3], 200, 150, 0);

    setAtlasColor(255, 255, 255, 255);
}

void drawColoredCube(void) {
    setAtlasColor(0, 0, 0, 255);
    blitAtlasImage(cube, 50, 450, 0);

    setAtlasColor(0, 0, 255, 255);
    blitAtlasImage(cube, 150, 450, 0);

    setAtlasColor(0, 255, 0, 255);
    blitAtlasImage(cube, 250, 450, 0);

    setAtlasColor(0, 255, 255, 255);
    blitAtlasImage(cube, 350, 450, 0);

    setAtlasColor(255, 0, 0, 255);
    blitAtlasImage(cube, 450, 450, 0);

    setAtlasColor(255, 0, 255, 255);
    blitAtlasImage(cube, 550, 450, 0);

    setAtlasColor(255, 255, 0, 255);
    blitAtlasImage(cube, 650, 450, 0);

    setAtlasColor(255, 255, 255, 255);
    blitAtlasImage(cube, 750, 450, 0);

    setAtlasColor(128, 128, 128, 100);
    blitAtlasImage(cube, 850, 450, 0);

    setAtlasColor(255, 255, 255, 255);
}

void drawScaledSprites(void) {
    blitAtlasImageScaled(cube, 700, 50, 32, 32);
    blitAtlasImageScaled(cube, 800, 50, 128, 32);
    blitAtlasImageScaled(cube, 1000, 50, 32, 128);
    blitAtlasImageScaled(tiles[0], 900, 250, tiles[0]->rect.w * 3, tiles[0]->rect.h * 3);
    blitAtlasImageScaled(tiles[1], 950, 450, tiles[1]->rect.w * 4, tiles[1]->rect.h * 4);
}
