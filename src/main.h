#ifndef MAIN_H
#define MAIN_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "../engine/init/init.h"
#include "../engine/draw/draw.h"
#include "../engine/sounds/sound.h"
#include "../engine/text/text.h"

void mainloop(void);

#endif