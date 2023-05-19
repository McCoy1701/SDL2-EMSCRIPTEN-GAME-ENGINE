#include "main.h"

void tick(void) {    
    drawText(510, 480, 255, 255, 255, TEXT_CENTER, 1, "TESTING");
    
    if (app.keyboard[SDL_SCANCODE_LCTRL]) {
        playSound(&playerSnd);
        app.keyboard[SDL_SCANCODE_LCTRL] = 0;
    }
}

void mainloop(void) {
    prepareScene();
    
    tick();
    
    presentScene();
}

int main(int argc, char** argv) {
    init();

    #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(mainloop, -1, 1);
    #endif

    #ifndef __EMSCRIPTEN__
        while(1) {
            mainloop();
        }
    #endif

    quit();

    return 0;
}
