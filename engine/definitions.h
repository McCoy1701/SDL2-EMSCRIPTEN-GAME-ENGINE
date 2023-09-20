#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string.h>

#define FPS 60

#define MAX_KEYBOARD_KEYS   350
#define MAX_NAME_LENGTH     100
#define MAX_LINE_LENGTH     1024
#define MAX_FILENAME_LENGTH 256

#define CELL_SIZE 24

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720

#define MAP_OFFSET_X 0
#define MAP_OFFSET_Y 300

#define TILE_WIDTH  24
#define TILE_HEIGHT 12

#define MAP_WIDTH  SCREEN_WIDTH  / CELL_SIZE
#define MAP_HEIGHT SCREEN_HEIGHT / CELL_SIZE

#define GLYPH_WIDTH  7
#define GLYPH_HEIGHT 9

#define NUM_ATLAS_BUCKETS 64
#define NUM_OF_BLOCKS 256 
#define NUM_OF_UI_ITEMS 256 

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
