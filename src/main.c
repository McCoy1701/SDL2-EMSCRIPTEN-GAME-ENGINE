#include "main.h"

void mainloop(void) {
    // prepareScene();

    // gameLoop();
    
    // presentScene();
    printf("loop\n");
}

int main(int argc, char** argv) {
    // init();

    printf("hello?\n");
    
    // initGame();
    
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
