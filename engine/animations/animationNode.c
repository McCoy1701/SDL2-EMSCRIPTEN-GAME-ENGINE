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

void appendAnimationNode(Entity* list, const char* name, Animation* animation) {
    AnimationNode* newNode = animationNodeConstructor(name, animation);
    newNode->name = name;
    newNode->animation = animation;
    newNode->next = list->animationsHead;
    newNode->prev = NULL;

    if (list->animationsHead == NULL) {
        list->animationsHead = newNode;
    }
    
    list->animationsHead = newNode;
}

void loadAnimationsFromFile(Entity* entity, const char* filename) {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(filename)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {                                                              //Loop through all the directories
            if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {                           //skip the current directory "." and parent directory ".."
                continue;
            }

            printf("file name: %s\n", ent->d_name);
        }

        closedir(dir);
    } else {
        printf("Error opening directory %s\n", filename);
    }
}
