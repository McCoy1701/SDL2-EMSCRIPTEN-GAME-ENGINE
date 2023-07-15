#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include "definitions.h"

typedef void (*voidFunctionPointer)(void);

typedef struct _delegate {
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

typedef struct _animation {
    int frameCount;
    int frame;
    uint32_t msPerFrame;
    SDL_Surface** animationFrames;
} Animation;

typedef struct _surface {
    char name[MAX_NAME_LENGTH];
    SDL_Surface* surface;
    struct _surface *next;
} Surface;

typedef struct _mouse {
    int x;
    int y;
} Mouse;

typedef struct _audioClip {
    char filename[MAX_NAME_LENGTH];
    SDL_AudioSpec spec;
    uint32_t length;
    uint8_t* buffer;
} AudioClip;

typedef struct _app {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_AudioDeviceID deviceID;
    Delegate delegate;
    int keyboard[MAX_KEYBOARD_KEYS];
    Surface surfaceHead, *surfaceTail;
} App;

#endif