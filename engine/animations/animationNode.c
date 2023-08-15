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
            char** tokens = tokenizeString(ent->d_name, "-x.", filename);

            char* imagePath = (char*)malloc(strlen(filename) + strlen(ent->d_name) + 1);
            memset(imagePath, 0, strlen(filename) + strlen(ent->d_name) + 1);

            strcpy(imagePath, filename);
            strcat(imagePath, "/");
            strcat(imagePath, ent->d_name);

            char* name = tokens[0];
            int x = atoi(tokens[1]);
            int y = atoi(tokens[2]);
            int frameCount = atoi(tokens[3]);
            int msPerFrame = atoi(tokens[4]);
            
            Animation* animation = animationConstructor(sliceSpriteSheet(imagePath, x, y, frameCount), frameCount, msPerFrame);
            appendAnimationNode(entity, name, animation);

            for (int i = 0; i < 5; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(imagePath);
        }

        closedir(dir);
    } else {
        printf("Error opening directory %s\n", filename);
    }
}
