#include "2d.h"

#include <math.h>

vec2* vec2Constructor(float x, float y) {
    vec2* vector = (vec2*)malloc(sizeof(vec2));
    vector->x = x;
    vector->y = y;
    return vector;
}

void vec2Deconstructor(vec2* vector) {
    free(vector);
}

void vec2Add(vec2* returnVector, vec2* vectorA, vec2* vectorB) {
    returnVector->x = (vectorA->x + vectorB->x);
    returnVector->y = (vectorA->y + vectorB->y);
}

void vec2Sub(vec2* returnVector, vec2* vectorA, vec2* vectorB) {
    returnVector->x = (vectorA->x - vectorB->x);
    returnVector->y = (vectorA->y - vectorB->y);
}

void vec2Min(vec2* returnVector, vec2* vectorA, vec2* vectorB) {
    returnVector->x = (vectorA->x < vectorB->x ? vectorA->x : vectorB->x);
    returnVector->y = (vectorA->y < vectorB->y ? vectorA->y : vectorB->y);
}

void vec2Max(vec2* returnVector, vec2* vectorA, vec2* vectorB) {
    returnVector->x = (vectorA->x > vectorB->x ? vectorA->x : vectorB->x); 
    returnVector->y = (vectorA->y > vectorB->y ? vectorA->y : vectorB->y);
}

void vec2ScaleDiv(vec2* returnVector, vec2* vectorA, float value) {
    returnVector->x = (vectorA->x / value);
    returnVector->y = (vectorA->y / value);
}

void vec2ScaleMul(vec2* returnVector, vec2* vectorA, float value) {
    returnVector->x = (vectorA->x * value);
    returnVector->y = (vectorA->y * value);
}

void vec2Normalize(vec2* returnVector, vec2* vectorA) {
    float magnitude;
    magnitude = vec2Magnitude(vectorA);
    if (!magnitude) {
        returnVector = vectorA;
    } else {
        returnVector->x = (vectorA->x / magnitude);
        returnVector->y = (vectorA->y / magnitude);
    }
}

vec2* vec2Zero(void) {
    vec2* vector = (vec2*)malloc(sizeof(vec2));
    vector->x = 0;
    vector->y = 0;
    return vector;
}

float vec2DotProduct(vec2* vectorA, vec2* vectorB) {
    return ((vectorA->x * vectorB->x) + (vectorA->y * vectorB->y));
}

float vec2Magnitude(vec2* vectorA) {
    return sqrtf((vectorA->x * vectorA->x) + (vectorA->y * vectorA->y));
}

void vec2Limit(vec2* vectorA, float value) {
    if (vec2Magnitude(vectorA) > value) {
        vec2Normalize(vectorA, vectorA);
        vec2ScaleMul(vectorA, vectorA, value);
    }
}
