#include "ui.h"


Button* buttonConstructor(float x, float y, const char* text, SDL_Surface* surf) {
    Button* newButton = (Button*)malloc(sizeof(Button));
    newButton->x = x;
    newButton->y = y;
    strcpy(newButton->text, text);
    newButton->surf = surf;
    newButton->w = newButton->surf->w;
    newButton->h = newButton->surf->h;
    
    return newButton;
}

void isHovering(Button* button) {
    int* mousex, *mousey;
    SDL_GetMouseState(mousex, mousey);

    if (*mousex >= button->x && *mousex <= button->w && *mousey >= button->y && *mousey <= button->h ) {
        button->hovering = 1;
    
    } else {
    
        button->hovering = 0;
    }
}

void isPressed(Button* button) {
    int* mousex, *mousey;
    SDL_Event event;
    SDL_GetMouseState(mousex, mousey);
    while (SDL_PollEvent(&event) != 0) {

        if ((*mousex >= button->x && *mousex <= button->w && *mousey >= button->y && *mousey <= button->h) 
        && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        
            button->clicked= 1;

        } else {

            button->clicked= 0;
        }

    }
}
