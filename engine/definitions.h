#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string.h>

#define FPS 60

#define MAX_KEYBOARD_KEYS 350
#define MAX_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1024

#define CELL_SIZE 16

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAP_WIDTH SCREEN_WIDTH / CELL_SIZE
#define MAP_HEIGHT SCREEN_HEIGHT / CELL_SIZE

#define GLYPH_WIDTH 7
#define GLYPH_HEIGHT 9

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define RANDF(upper, lower) (((float)rand() / (float)(RAND_MAX)) * (upper - lower)) + lower

enum {
    TEXT_LEFT,
    TEXT_CENTER,
    TEXT_RIGHT
};

#endif
