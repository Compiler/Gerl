#pragma once
#include <math.h>


typedef struct Vector3{
    float x;
    float y;
    float z;
}vec3;


float TYPE_length(vec3* vecA);
void vec3_addTo(vec3* vecA, vec3* vecB);
void vec3_addValTo(vec3* vecA, float val);
void vec3_subFrom(vec3* vecA, vec3* vecB);
void vec3_subValFrom(vec3* vecA, float val);
void vec3_mulTo(vec3* vecA, vec3* vecB);
void vec3_mulValTo(vec3* vecA, float val);
void vec3_divTo(vec3* vecA, vec3* vecB);
void vec3_divValTo(vec3* vecA, float val);

void vec3_unitVector(vec3* vecA);