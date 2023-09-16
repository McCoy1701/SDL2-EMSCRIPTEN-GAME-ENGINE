#include "game.h"

Entity* player;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    doInput();
    // updateWorld(MAP);
}

void renderLoop(void) {
    displayWorld(MAP);
    drawText(100, 100, 255, 255, 255, TEXT_LEFT, 1, "BIG FAT BITCHES");
}

void initGame(void) {
    // printf("shitter\n");
    initTiles();
    generateWorld();
    // player = entityConstructor(vec2Constructor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), "assets/player");
}

void quitGame(void) {
    // entityDeconstructor(player);
    // animationNodeDeconstructor(testNode);
    // quitWorld(MAP);
}
