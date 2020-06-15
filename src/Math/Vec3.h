#pragma once

typedef struct vec3{
    float x;
    float y;
    float z;
}vec3;

void addTo(vec3* vecA, vec3* vecB);
void subFrom(vec3* vecA, vec3* vecB);
void mulTo(vec3* vecA, vec3* vecB);
void divTo(vec3* vecA, vec3* vecB);
