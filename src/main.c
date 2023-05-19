#include "main.h"

void tick(void) {
    mainloop();
    // app.delegate.logic();
    // app.delegate.draw();
}

void mainloop(void) {
    presentScene();
    prepareScene();
}

int main(int argc, char** argv) {
    init();
    
    initSounds();

    playSound(&playerSnd);

    #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(tick, -1, 1);
    #endif

    #ifndef __EMSCRIPTEN__
        while(1) {
            tick();
        }
    #endif

    quit();
    
    return 0;
}
