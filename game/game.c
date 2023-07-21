#include "game.h"

Cell** MAP;
Character* player;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    updateWorld(MAP);
}

void renderLoop(void) {
    displayWorld(MAP);
    drawSurfaces(player);
}

void initGame(void) {
    MAP = allocateWorldMemory();
    generateWorld(MAP);
    player = constructCharacter(vec2Constructor(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
}

void quitGame(void) {
    deconstructCharacter(player);
    quitWorld(MAP);
}
