#include "game.h"

Cell** MAP;
Character* player;
AnimationNode* testNode;

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
    testNode = loadAnimationsFromFile("assets/player");
    player = constructCharacter(vec2Constructor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
}

void quitGame(void) {
    deconstructCharacter(player);
    animationNodeDeconstructor(testNode);
    quitWorld(MAP);
}
