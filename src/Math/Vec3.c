#include "Vec3.h"

void addTo(vec3 *vecA, vec3* vecB){
    vecA->x += vecB->x;
    vecA->y += vecB->y;
    vecA->z += vecB->z;
}
void subFrom(vec3 *vecA, vec3* vecB){
    vecA->x -= vecB->x;
    vecA->y -= vecB->y;
    vecA->z -= vecB->z;
}
void mulTo(vec3 *vecA, vec3* vecB){
    vecA->x *= vecB->x;
    vecA->y *= vecB->y;
    vecA->z *= vecB->z;
}
void divTo(vec3 *vecA, vec3* vecB){
    vecA->x /= vecB->x;
    vecA->y /= vecB->y;
    vecA->z /= vecB->z;
}
//void subFrom(vec3* vecA, vec3* vecB);
//void mulTo(vec3* vecA, vec3* vecB);
//void divTo(vec3* vecA, vec3* vecB);