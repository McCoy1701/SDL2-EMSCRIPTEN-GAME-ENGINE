#ifndef TEXT_H
#define TEXT_H

#include "../init/init.h"
#include "../draw/draw.h"

extern SDL_Texture* fontTexture;

static char drawTextBuffer[MAX_LINE_LENGTH];

void initFont(void);

void drawText(int x, int y, int r, int g, int b, int align, int scale, char *format, ...);

#endif