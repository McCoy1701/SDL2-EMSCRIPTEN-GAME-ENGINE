#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include "definitions.h"
#include "draw/2d.h"

typedef void (*voidFunctionPointer)(void);

typedef struct _character {
    vec2* position;
    vec2* velocity;
    int surfaceCount;
    SDL_Surface** surfaces;
} Character;

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

typedef struct _deltaTime {
    Uint32 lastTime;
    Uint32 currentTime;
} DeltaTime;

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
    DeltaTime deltaTime;
    Surface surfaceHead, *surfaceTail;
} App;

#endif