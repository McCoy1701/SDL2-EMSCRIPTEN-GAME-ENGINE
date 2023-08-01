#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "../structs.h"
#include "../utils/deltaTime/deltaTime.h"
#include "../sprites/spriteSlicer.h"
#include "../utils/utils.h"

Animation* animationConstructor(const char* filename, vec2* cellSize, int numFrames, uint32_t msPerFrame);

AnimationNode* animationNodeConstructor(char* name, Animation* animation);

void animationDeconstructor(Animation* animation);

void animationNodeDeconstructor(AnimationNode* head);

void playAnimation(Animation* animation);

void appendAnimationNode(AnimationNode** head, char* name, Animation* animation);

Animation* findAnimation(AnimationNode** head, char* name);

AnimationNode* loadAnimationsFromFile(char* filename);

#endif