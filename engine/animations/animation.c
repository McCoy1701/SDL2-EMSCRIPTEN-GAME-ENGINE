#include "animation.h"

Animation* animationConstructor(SDL_Surface** aniFrames, int numFrames, uint32_t msPerFrame) {
    Animation* animation = (Animation*)malloc(sizeof(Animation));
    animation->frameCount = numFrames;
    animation->msPerFrame = msPerFrame;
    animation->animationFrames = aniFrames;
    animation->frame = 0;
    animation->accumulated = 0;

    return animation;
}

void animationDeconstructor(Animation* animation) {
    for (int i = 0; i < animation->frameCount; i++) {
        SDL_FreeSurface(animation->animationFrames[i]);
    }

    free(animation->animationFrames);
    free(animation);
}

void playAnimation(Animation* animation) {
    animation->accumulated += getDeltaTime();
    if (animation->accumulated >= animation->msPerFrame) {
        animation->frame = (animation->frame + 1) % animation->frameCount;
        animation->accumulated -= animation->msPerFrame;
    }
}

void printAnimationList(Entity* list) {
    AnimationNode* temp = list->animationsHead;

    while(temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

Animation* findAnimation(AnimationNode* head, const char* name) {
    char* temp;
    AnimationNode* tempNode = head;
    Animation* animation;
    STRNCPY(temp, tempNode->name, MAX_NAME_LENGTH);
    
    while (tempNode != NULL) {
        if (strcmp(temp, name)) {
            animation = tempNode->animation;
        }

        tempNode = tempNode->next;
    }
    return animation;
}
