#include "game.h"

Cell** MAP;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    updateWorld(MAP);
}

void renderLoop(void) {
    displayWorld(MAP);
}

void initGame(void) {
    MAP = allocateWorldMemory();
    generateWorld(MAP);
}

void quitGame(void) {
    quitWorld(MAP);
}
