#include "game.h"

vec2* position;
vec2* velocity;
int radius;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    position->x += velocity->x;
    position->y += velocity->y;

    if ((position->x < 0) || (position->x > SCREEN_WIDTH - radius)) {
        velocity->x *= -1;
    }
    
    if ((position->y < 0) || (position->y > SCREEN_HEIGHT - radius)) {
        velocity->y *= -1;
    }
}

void renderLoop(void) {
    drawCircle(position->x, position->y, radius);
}

void initGame(void) {
    position = vec2Constructor(0, 0);
    velocity = vec2Constructor(1, 3.3);
    radius = 5;
}
