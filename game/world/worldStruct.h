#ifndef worldStruct_H
#define worldStruct_H

#include "../../engine/utils/vector/vector.h"
#include "../globals/global.h"

typedef struct _cell {
    int x;
    int y;
    int w;
    int h;
    int hovering;
    Types type;
    int id;
} Cell;

#endif
