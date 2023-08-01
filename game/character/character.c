#include "character.h"

Entity* constructEntity (vec2* position) {
    Entity* player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));
    
    stage.entityTail->next = player;
    stage.entityTail = player;
    
    return player;
}

void drawSurfaces(Entity* player) {
    
}

void deconstructCharacter(Entity* player) {
    free(player->position);
    free(player->velocity);

    animationNodeDeconstructor(&player->animationsHead);
    animationNodeDeconstructor(player->animationsTail);

    free(player);
}
