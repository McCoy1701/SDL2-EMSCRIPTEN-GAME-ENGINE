#include "deltaTime.h"

float getDeltaTime(void) {
    app.deltaTime.lastTime = app.deltaTime.currentTime;
    app.deltaTime.currentTime = SDL_GetTicks();
    Uint32 elapsedTime = app.deltaTime.currentTime - app.deltaTime.lastTime;
    return(float)elapsedTime / 1000.0f;
}
