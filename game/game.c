#include "game.h"

Entity* player;
// Button* backButton;
// Button* forwardButton;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    doInput();
    
    // updateWorld(MAP);
}

void renderLoop(void) {
    // drawGrid(uiArray, 50 , 50, 16, 16);
    // drawGrids(backButton, forwardButton, 50 , 50);
    // testDisplay();
    // displayWorld(MAP);
    drawText(100, 100, 255, 255, 255, TEXT_LEFT, 1, "BIG FAT BITCHES");
}

void initGame(void) {
    printf("shitter\n");
    // backButton    = buttonConstructor(400, 400, "BACK",    NULL);
    // forwardButton = buttonConstructor(500, 400, "FORWARD", NULL);
    initTiles();
    generateWorld();
    // player = entityConstructor(vec2Constructor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), "assets/player");
}

void quitGame(void) {
    // entityDeconstructor(player);
    // animationNodeDeconstructor(testNode);
    // quitWorld(MAP);
    // buttonsDeconstructor(backButton);
    // buttonsDeconstructor(forwardButton);
}
