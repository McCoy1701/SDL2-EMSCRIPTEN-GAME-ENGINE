#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../structs.h"
#include "../sprites/spriteSlicer.h"

Animation* animationConstructor(const char* filename, int numFrames, uint32_t msPerFrame);

void playAnimation(Animation* animation);

void animationDeconstructor(Animation* animation);

AnimationNode* animationNodeConstructor(const char* name, Animation* animation);

void apendAnimationNode(AnimationNode** head, const char* name, Animation* animation);

Animation* findAnimation(AnimationNode** head, const char* name);

void animationNodeQuit(AnimationNode* head);

#endif