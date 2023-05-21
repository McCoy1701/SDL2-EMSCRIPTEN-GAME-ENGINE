#include "animation.h"

Animation* createAnimation(int numFrames, uint32_t msPerFrame) {
    Animation* animation = (Animation*)malloc(sizeof(Animation));
    animation->frameCount = numFrames;
    animation->msPerFrame = msPerFrame;
    animation->frame = 0;
    animation->animationFrames = (SDL_Surface**)malloc(numFrames * sizeof(SDL_Surface*));

    return animation;
}

void destroyAnimation(Animation* animation) {
    for (int i = 0; i < animation->frameCount; i++) {
        SDL_FreeSurface(animation->animationFrames[i]);
    }

    free(animation->animationFrames);
    free(animation);
}

int loadFrame(Animation* animation, SDL_Renderer* renderer, char* filename) {
    char* tempName;
    for (int i = 0; i < animation->frameCount; i++) {
        sprintf("%s%d%s", filename, i, ".png");
        SDL_Surface* surf = IMG_Load(tempName);
        if (!surf) {
            printf("Error loading file: %s%s\n", tempName, SDL_GetError());
            return 0;
        }
        
        animation->animationFrames[i] = surf;
        if (!animation->animationFrames[i]) {
            printf("Error loading file: %s%s\n", tempName, SDL_GetError());
            return 0;
        }
    }
    return 1;
}
