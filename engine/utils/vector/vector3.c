#include "vector.h"

vec3* vec3Constructor(float x, float y, float z) {
    vec3* vector = (vec3*)malloc(sizeof(vec3));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}

void vec3Deconstructor(vec3* vector) {
    free(vector);
}