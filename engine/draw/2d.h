#ifndef TWOD_H
#define TWOD_H

#include <stdio.h>
#include <stdlib.h>
#include "../definitions.h"

typedef struct _vec2 {
    float x;
    float y;
} vec2;

vec2* vec2Constructor(float x, float y);

void vec2Deconstructor(vec2* vector);

void vec2Add(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec2Sub(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec2Min(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec2Max(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec2ScaleDiv(vec2* returnVector, vec2* vectorA, float value);
void vec2ScaleMul(vec2* returnVector, vec2* vectorA, float value);
void vec2Normalize(vec2* returnVector, vec2* vectorA);
void vec2Limit(vec2* vectorA, float value);

vec2* vec2Zero(void);

float vec2DotProduct(vec2* vectorA, vec2* vectorB);
float vec2Magnitude(vec2* vectorA);

#endif