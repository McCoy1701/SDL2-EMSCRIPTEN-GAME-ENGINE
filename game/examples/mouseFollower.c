#include "game.h"

Mover* mover;
float topspeed;

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
    mover->velocity = vec2Constructor(0, 0);
    mover->acceleration = vec2Zero();
    topspeed = 5;
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
    float randx = RANDF(SCREEN_WIDTH, 0); float randy = RANDF(SCREEN_HEIGHT, 0);
    vec2* temp = vec2Constructor(randx, randy);
    mover->acceleration = temp;
    free(temp);
    // int random;
    // random = rand() % 10;
    vec2ScaleMul(mover->acceleration, mover->acceleration, 2);
    vec2Add(mover->velocity, mover->velocity, mover->acceleration);
    vec2Limit(mover->velocity, topspeed);
    vec2Add(mover->position, mover->position, mover->velocity);
}

void display(Mover* mover) {
    drawCircle(mover->position->x, mover->position->y, 32);
    drawText(50, 50, 255, 255, 255, TEXT_LEFT, 0, "VELOCITY: %.3f %.3f\n", mover->velocity->x, mover->velocity->y);
}
