#include "input.h"


void doInput() {
    SDL_Event event;
    
    pressed = 0;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            
            case SDL_KEYDOWN:
                if (!pressed) {
                    doKeyDown(&event.key);
                }
                break;
            
            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;

            default:
                break;
        
        }
    }
}

void doKeyDown(SDL_KeyboardEvent* event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS) {
        app.keyboard[event->keysym.scancode] = 1;
    }
    pressed = 1;
}

void doKeyUp(SDL_KeyboardEvent* event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS) {
        app.keyboard[event->keysym.scancode] = 0;
    }
    pressed = 0;
}
