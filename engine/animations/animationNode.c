#include "animation.h"

AnimationNode* animationNodeConstructor(char* name, Animation* animation) {
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

void appendAnimationNode(AnimationNode** head, char* name, Animation* animation) {
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

void loadAnimationsFromFile(Entity* entity, char* filename) {
    DIR* dir;
    struct dirent* ent;
    
    if ((dir = opendir(filename)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            char** tokens = tokenizeString(ent->d_name, "-x.");
            
            char* imagePath = malloc(strlen(filename) + strlen(ent->d_name) + 1);
            strcpy(imagePath, filename);
            strcat(imagePath, "/");
            strcat(imagePath, ent->d_name);

            printf("%d\n", sizeof(tokens));
            
            if (tokens[0] != NULL) {
                char* name = tokens[0];
                int x = atoi(tokens[1]);
                int y = atoi(tokens[2]);
                int frameCount = atoi(tokens[3]);
                int msPerFrame = atoi(tokens[4]);

                Animation* animation = animationConstructor(imagePath, vec2Constructor(x, y), frameCount, msPerFrame);
            }
            
            for (int i = 0; tokens[i] != NULL; i++) {
                free(tokens[i]);
            }

            free(tokens);
            free(imagePath);
        }

        closedir(dir);
    } else {
        printf("Error opening directory %s\n", filename);
        return NULL;
    }
    
    return NULL;
}
