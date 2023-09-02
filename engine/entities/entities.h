#ifndef ENTITIES_H
#define ENTITIES_H

#include "../init/init.h"
#include "../animations/animation.h"
#include "../structs.h"
#include "../utils/vector/vector.h"

Entity* entityConstructor(vec2* position, const char* filename);
void entityDeconstructor(Entity* entity);

#endif