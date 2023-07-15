#include "game.h"

vec2* mouse;
vec2* center;
vec2* temp;
int* x;
int* y;
Uint32* buttonMask;
float* mag;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    *buttonMask = SDL_GetGlobalMouseState(x, y);
    mouse->x = *x; mouse->y = *y;
    vec2Sub(mouse, mouse, center);
    *mag = vec2Magnitude(mouse);
    // vec2Normalize(mouse, mouse);
    // vec2ScaleMul(mouse, mouse, 50);
}

void renderLoop(void) {
    drawLine(center->x, center->y, mouse->x + center->x, mouse->y + center->y);
    drawHoriLine(0, (int)*mag, 10);
    drawText(50, 50, 255, 0, 0, TEXT_LEFT, 0, "MOUSE SCALED: %.1f, %.1f | (X,Y): %d, %d", mouse->x, mouse->y, *x, *y);
}

void initGame(void) {
    mouse = (vec2*)malloc(sizeof(vec2));
    temp = vec2Zero();
    center = vec2Constructor(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    x = (int*)malloc(sizeof(int));
    y = (int*)malloc(sizeof(int));
    mag = (float*)malloc(sizeof(float));
    buttonMask = (Uint32*)malloc(sizeof(Uint32));
}

void quitGame(void) {
    free(mouse);
    free(temp);
    free(center);
    free(x);
    free(y);
    free(mag);
    free(buttonMask);
}
