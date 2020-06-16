#pragma once
#include <math.h>

typedef struct vec3{
    float x;
    float y;
    float z;
}vec3;


float length(vec3* vecA);
void addTo(vec3* vecA, vec3* vecB);
void addTo(vec3* vecA, float val);
void subFrom(vec3* vecA, vec3* vecB);
void subFrom(vec3* vecA, float val);
void mulTo(vec3* vecA, vec3* vecB);
void mulTo(vec3* vecA, float val);
void divTo(vec3* vecA, vec3* vecB);
void divTo(vec3* vecA, float val);

void unitVector(vec3* vecA);