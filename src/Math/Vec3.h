#ifndef VEC3_H
#define VEC3_H
#pragma once

#include <math.h>


typedef struct Vector3{
    float x;
    float y;
    float z;
}vec3;


float vec3_length(vec3* vecA);
void vec3_addTo(vec3* vecA, vec3* vecB);
void vec3_addValTo(vec3* vecA, float val);
void vec3_subFrom(vec3* vecA, vec3* vecB);
void vec3_subValFrom(vec3* vecA, float val);
void vec3_mulTo(vec3* vecA, vec3* vecB);
void vec3_mulValTo(vec3* vecA, float val);
void vec3_divTo(vec3* vecA, vec3* vecB);
void vec3_divValTo(vec3* vecA, float val);
void vec3_set(vec3* vecA, float x, float y, float z);

vec3 vec3_unitVector(vec3* vecA);

#endif