#ifndef UI_STRUCTS_H
#define UI_STRUCTS_H

#include <SDL2/SDL.h>

typedef struct _button {
    float x;
    float y;
    int w;
    int h;
    int hovering;
    int clicked;
    char* text;
    SDL_Surface* surf;
} Button;

#endif