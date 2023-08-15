#include "character.h"

Entity* constructEntity (vec2* position, const char* filename) {
    Entity* player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    // loadAnimationsFromFile(player, filename);

    stage.entityTail->next = player;
    stage.entityTail = player;
    
    return player;
}

void drawSurfaces(Entity* player) {
    
}

void deconstructEntity(Entity* player) {
    free(player->position);
    free(player->velocity);

    animationNodeDeconstructor(player->animationsHead);

    free(player);
}
