#ifndef RAY_H
#define RAY_H
#pragma once

#include <Math/Vec3.h>

//24 bytes
typedef struct Ray{
    vec3 position;
    vec3 direction;
}ray;

vec3 ray_getPositionAt(const ray* currentRay, double t);
void ray_setPosition(ray* currentRay, float x, float y, float z);
void ray_setDirection(ray* currentRay, float x, float y, float z);

vec3 ray_color(const ray* currentRay);

#endif