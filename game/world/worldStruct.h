#ifndef worldStruct_H
#define worldStruct_H

#include "../../engine/draw/2d.h"

typedef struct _cell {
    int x;
    int y;
    int w;
    int h;
    int hovering;
} Cell;

#endif
