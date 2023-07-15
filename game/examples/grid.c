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
    displayMap(MAP);
}

void initGame(void) {
    MAP = malloc(MAP_HEIGHT * sizeof(Cell*));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        MAP[i] = malloc(MAP_WIDTH * sizeof(Cell));
    }
    generateWorld(MAP);
}

void quitGame(void) {
    quitWorld(MAP);
}
