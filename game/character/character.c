#include "character.h"

Character* constructCharacter (vec2* position) {
    Character* player = malloc(sizeof(Character));
    
    player->position = position;
    player->velocity = vec2Zero();
    player->surfaceCount = 8;
    
    player->surfaces = sliceSpriteSheet("assets/playerSheet.png",
    vec2Constructor(16, 16), player->surfaceCount);
    
    return player;
}

void drawSurfaces(Character* player) {
    for (int i = 0; i < player->surfaceCount; i++) {
        blit(player->surfaces[i], player->position->x, player->position->y);
        sleep(1);
    }
}

void deconstructCharacter(Character* player) {
    free(player->position);
    free(player->velocity);

    for (int i = 0; i < player->surfaceCount; i++) {
        SDL_FreeSurface(player->surfaces[i]);
    }

    free(player);
}
