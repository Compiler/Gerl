#ifndef RAY_H
#define RAY_H
#pragma once


#include <Math/Vec3.h>

typedef struct Ray{
    vec3 position;
    vec3 direction;
}ray;

vec3 ray_getPositionAt(const ray* currentRay, double t);

#endif