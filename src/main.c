#include "main.h"

void mainloop(void) {
    prepareScene();
    drawText(510, 480, 255, 255, 255, TEXT_CENTER, 1, "TESTING");
    presentScene();
}

int main(int argc, char** argv) {
    init();
    
    initSounds();

    initFont();

    playSound(&playerSnd);
      
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
