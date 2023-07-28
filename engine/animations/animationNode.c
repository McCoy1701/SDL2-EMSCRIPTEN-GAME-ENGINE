#include "animation.h"

AnimationNode* animationNodeConstructor(const char* name, Animation* animation) {
    AnimationNode* newNode = (AnimationNode*)malloc(sizeof(AnimationNode));
    if (newNode != NULL){
        newNode->name = name;
        newNode->animation = animation;
        newNode->next = NULL;
    }
    return newNode;
}

void animationNodeDeconstructor(AnimationNode* head) {
    while(head->next != NULL) {
        AnimationNode* temp = head;
        head = head->next;
        free(temp->animation->animationFrames);
        free(temp);
    }
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

AnimationNode* loadAnimationsFromFile(const char* filename) {
    DIR* dir;
    struct dirent* ent;
    AnimationNode* head;
    
    if ((dir = opendir(filename)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }

        closedir(dir);
    } else {
        printf("Error opening directory %s\n", filename);
        return NULL;
    }
    
    return NULL;
}
