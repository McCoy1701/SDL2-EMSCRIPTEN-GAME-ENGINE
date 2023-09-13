#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "uiStructs.h"

// BUTTONS

Button* buttonConstructor(float x, float y, const char* text, SDL_Surface* surf);

void isHovering(Button* button);

void isPressed(Button* button);

Buttons* newButtons(const char* name, int id);

void appendButtonToButtons(Ui* node, Button* src, int id);

void buttonsDeconstructor(Buttons* node);


//UI

Ui* uiConstructor(void);

#endif