#include "character.h"

Character* constructCharacter (vec2* position) {
    Character* player = malloc(sizeof(Character));
    
    player->position = position;
    player->velocity = vec2Zero();
    
    player->animations = malloc(sizeof(AnimationNode));
    
    return player;
}

void drawSurfaces(Character* player) {
    
}

void deconstructCharacter(Character* player) {
    free(player->position);
    free(player->velocity);

    animationNodeQuit(player->animations);

    free(player);
}
