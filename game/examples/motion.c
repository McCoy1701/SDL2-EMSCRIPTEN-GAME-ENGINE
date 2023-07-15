#include "game.h"

Mover* mover;

void gameLoop(void) {
    doLoop();
    renderLoop();
}

void doLoop(void) {
    checkEdges(mover);
    update(mover);
}

void renderLoop(void) {
    display(mover);
}

void initGame(void) {
    mover = (Mover*)malloc(sizeof(Mover));
    float randPosx = RANDF(SCREEN_WIDTH, 0.0);float randPosy = RANDF(SCREEN_HEIGHT, 0.0);
    float randVelx = RANDF(10.0, -10.0f); float randVely = RANDF(10.0, -10.0f); 
    mover->position = vec2Constructor(randPosx, randPosy);
    mover->velocity = vec2Constructor(randVelx, randVely);
}

void quitGame(void) {
    free(mover->position);
    free(mover->velocity);
    free(mover);
}

void checkEdges(Mover* mover) {
    if (mover->position->x > SCREEN_WIDTH) {
        mover->position->x = 0;
    } 
    
    else if (mover->position->x < 0) {
        mover->position->x = SCREEN_WIDTH;
    }

    if (mover->position->y > SCREEN_HEIGHT) {
        mover->position->y = 0;
    } 
    
    else if (mover->position->y < 0) {
        mover->position->y = SCREEN_HEIGHT;
    }
}

void update(Mover* mover) {
    vec2Add(mover->position, mover->position, mover->velocity);
}

void display(Mover* mover) {
    drawCircle(mover->position->x, mover->position->y, 32);
}
