#ifndef MAIN_H
#define MAIN_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "../game/game.h"

void mainloop(void);

#endif