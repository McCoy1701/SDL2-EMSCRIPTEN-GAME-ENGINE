#include "game.h"

Cell** MAP;
Character* player;

int currentIndex = 0;
float accmulatedTime = 0;

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
    drawSurfaces(player, currentIndex);
    accmulatedTime += getDeltaTime();
    if (accmulatedTime >= 0.1f) {
        currentIndex = (currentIndex + 1) % player->surfaceCount;
        accmulatedTime = 0;
    }
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
