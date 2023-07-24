#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../structs.h"
#include "../sprites/spriteSlicer.h"

Animation* animationConstructor(const char* filename, int numFrames, uint32_t msPerFrame);

AnimationNode* animationNodeConstructor(const char* name, Animation* animation);

void animationDeconstructor(Animation* animation);

void animationNodeDeconstructor(AnimationNode* head);

void playAnimation(Animation* animation);

void apendAnimationNode(AnimationNode** head, const char* name, Animation* animation);

Animation* findAnimation(AnimationNode** head, const char* name);

#endif