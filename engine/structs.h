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

typedef struct _card {
    const char* name;
    int x;
    int y;
    int w;
    int h;
    int generationAmount;
    SDL_Rect progressBar;
    SDL_Surface* cardSurf;
    SDL_Surface* itemSurf;
    struct _card* next;
} Card;

typedef struct _profile {
    const char* name;
    int x;
    int y;
    int w;
    int h;
    SDL_Surface* cardSurf;
    SDL_Surface* npcSurf;
    struct _card* next;
} Profile;

typedef struct _player {
    SDL_Surface* icon;
} Player;

typedef struct _surface {
    char name[MAX_NAME_LENGTH];
    SDL_Surface* surface;
    struct _surface *next;
} Surface;

typedef struct _stage {
    Card cardHead, *cardTail;
    Profile profileHead, *profileTail;
} Stage;

typedef struct _title {
    Stage stage;
    Player player;
} Title;

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
    Title titleScreen;
    Surface surfaceHead, *surfaceTail;
} App;

#endif