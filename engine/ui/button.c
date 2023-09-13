#include "ui.h"

// Button

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

//Buttons

Buttons* newButtons(const char* name, int id) {
    Buttons* newButt = (Buttons*)malloc(sizeof(Buttons));
    strcpy(newButt->name, name);
    newButt->id = id;
    return newButt;
}

void appendButtonToButtons(Ui* node, Button* button, int id) {
    Buttons* newButton = newButtons(button->text, id);
    
    Ui* temp = node;
    
    newButton->button = button;
    newButton->next = NULL;
    
    if (node->buttonHead == NULL) {
        newButton->prev = NULL;
        node->buttonHead = newButton;
        return;
    }
    
    while(temp->buttonHead->next != NULL) {
        temp->buttonHead = temp->buttonHead->next;
    }

    temp->buttonHead->next = newButton;

    newButton->prev = temp;
    
    return;
}

void buttonsDeconstructor(Buttons* node) {
    while (node->next != NULL) {
        Buttons* temp = node;
        node = node->next;
        free(temp->button);
        free(temp);
    }
}
