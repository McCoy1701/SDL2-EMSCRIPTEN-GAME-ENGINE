#include "animation.h"

Animation* animationConstructor(const char* filename, int numFrames, uint32_t msPerFrame) {
    Animation* animation = (Animation*)malloc(sizeof(Animation));
    animation->frameCount = numFrames;
    animation->msPerFrame = msPerFrame;
    animation->frame = 0;
    animation->accumulated = 0;
    animation->animationFrames = sliceSpriteSheet(filename, vec2Constructor(16, 48), animation->frameCount);

    return animation;
}

void playAnimation(Animation* animation) {
    animation->accumulated += getDeltaTime();
    if (animation->accumulated >= animation->msPerFrame) {
        animation->frame = (animation->frame + 1) % animation->frameCount;
        animation->accumulated -= animation->msPerFrame;
    }
}

void animationDeconstructor(Animation* animation) {
    for (int i = 0; i < animation->frameCount; i++) {
        SDL_FreeSurface(animation->animationFrames[i]);
    }

    free(animation->animationFrames);
    free(animation);
}

AnimationNode* animationNodeConstructor(const char* name, Animation* animation) {
    AnimationNode* newNode = (AnimationNode*)malloc(sizeof(AnimationNode));
    if (newNode != NULL){
        newNode->name = name;
        newNode->animation = animation;
        newNode->next = NULL;
    }
    return newNode;
}

void apendAnimationNode(AnimationNode** head, const char* name, Animation* animation) {
    AnimationNode* newNode = animationNodeConstructor(name, animation);
    if (newNode == NULL) {
        printf("[Error] could not allocate memory\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    }
    
    else{
        AnimationNode* current = *head;
        while(current != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
}

Animation* findAnimation(AnimationNode** head, const char* name) {
    char* temp;
    AnimationNode* tempNode = *head;
    STRNCPY(temp, tempNode->name, MAX_NAME_LENGTH);
    
    while (tempNode != NULL) {
        if (strcmp(temp, name)) {
            return tempNode->animation;
        }

        tempNode = tempNode->next;
    }
}

void animationNodeQuit(AnimationNode* head) {
    while(head->next != NULL) {
        AnimationNode* temp = head;
        head = head->next;
        free(temp->animation->animationFrames);
        free(temp);
    }
}
