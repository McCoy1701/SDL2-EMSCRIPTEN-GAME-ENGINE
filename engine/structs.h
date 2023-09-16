#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include "definitions.h"
#include "utils/vector/vector.h"

typedef void (*voidFunctionPointer)(void);

typedef struct _image {
    char* filename;
    char* typeName;
    SDL_Surface* surface;
} Image;

typedef struct _node {
    int x;
    int y;
    int w;
    int h;
    int used;
    
    struct _node* child;
} Node;

typedef struct _atlasImage {
    char filename[MAX_FILENAME_LENGTH];
    SDL_Rect rect;
    int rotated;
    SDL_Texture* texture;
    struct _atlasImage *next;
} AtlasImage;

typedef struct _delegate {
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

typedef struct _animation {
    int frameCount;
    int frame;
    float accumulated;
    uint32_t msPerFrame;
    SDL_Surface** animationFrames;
} Animation;

typedef struct _animationNode {
    const char* name;
    Animation* animation;
    struct _animationNode* next;
    struct _animationNode* prev;
} AnimationNode;

typedef struct _surface {
    char name[MAX_NAME_LENGTH];
    SDL_Surface* surface;
    struct _surface* next;
} Surface;

typedef struct _deltaTime {
    Uint32 lastTime;
    Uint32 currentTime;
} DeltaTime;

typedef struct _mouse {
    int x;
    int y;
} Mouse;

typedef struct _entity {
    vec2* position;
    vec2* screenPosition;
    vec2* velocity;
    vec2* size;
    AnimationNode* animationsHead;
    struct _entity* next;
} Entity;

typedef struct _stage {
    Entity entityHead, *entityTail;
} Stage;

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