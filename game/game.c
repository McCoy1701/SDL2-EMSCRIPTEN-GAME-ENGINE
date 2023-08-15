#include "game.h"

Cell** MAP;
Entity* player;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    doInput();
    updateWorld(MAP);
}

void renderLoop(void) {
    displayWorld(MAP);
    drawSurfaces(player);
}

void initGame(void) {
    MAP = allocateWorldMemory();
    generateWorld(MAP);
    player = constructEntity(vec2Constructor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), "assets/player");
}

void quitGame(void) {
    // deconstructEntity(player);
    // animationNodeDeconstructor(testNode);
    quitWorld(MAP);
}
