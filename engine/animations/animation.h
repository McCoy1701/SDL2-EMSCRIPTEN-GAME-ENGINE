#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "../structs.h"
#include "../utils/deltaTime/deltaTime.h"
#include "../utils/utils.h"

Animation* animationConstructor(SDL_Surface** aniFrames, int numFrames, uint32_t msPerFrame);

AnimationNode* animationNodeConstructor(const char* name, Animation* animation);

void animationDeconstructor(Animation* animation);

void animationNodeDeconstructor(AnimationNode* head);

void playAnimation(Animation* animation);

void appendAnimationNode(Entity* list, const char* name, Animation* animation);

void printAnimationList(Entity* list);

Animation* findAnimation(AnimationNode* head, const char* name);

void loadAnimationsFromFile(Entity* entity, const char* filename);

#endif