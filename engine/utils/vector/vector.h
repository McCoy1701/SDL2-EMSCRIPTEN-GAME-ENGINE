#ifndef TWOD_H
#define TWOD_H

#include <stdio.h>
#include <stdlib.h>
#include "../../definitions.h"

typedef struct _vec2 {
    float x;
    float y;
} vec2;

typedef struct _vec3 {
    float x;
    float y;
    float z;
} vec3;

vec2* vec2Constructor(float x, float y);
vec3* vec3Constructor(float x, float y, float z);

void vec2Deconstructor(vec2* vector);
void vec3Deconstructor(vec3* vector);

void vec2Add(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec3Add(vec3* returnVector, vec3* vectorA, vec3* vectorB);
void vec2Sub(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec3Sub(vec3* returnVector, vec3* vectorA, vec3* vectorB);
void vec2Min(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec3Min(vec3* returnVector, vec3* vectorA, vec3* vectorB);
void vec2Max(vec2* returnVector, vec2* vectorA, vec2* vectorB);
void vec3Max(vec3* returnVector, vec3* vectorA, vec3* vectorB);
void vec2ScaleDiv(vec2* returnVector, vec2* vectorA, float value);
void vec3ScaleDiv(vec3* returnVector, vec3* vectorA, float value);
void vec2ScaleMul(vec2* returnVector, vec2* vectorA, float value);
void vec3ScaleMul(vec3* returnVector, vec3* vectorA, float value);
void vec2Normalize(vec2* returnVector, vec2* vectorA);
void vec3Normalize(vec3* returnVector, vec3* vectorA);
void vec2Limit(vec2* vectorA, float value);
void vec3Limit(vec3* vectorA, float value);

vec2* vec2Zero(void);
vec3* vec3Zero(void);

float vec2DotProduct(vec2* vectorA, vec2* vectorB);
float vec3DotProduct(vec3* vectorA, vec3* vectorB);
float vec3CrossProduct(vec3* vectorA, vec3* vectorB);
float vec2Magnitude(vec2* vectorA);
float vec3Magnitude(vec3* vectorA);

#endif