#include "Vec3.h"


float vec3_length(vec3* vecA){
    return sqrt(vecA->x * vecA->x + vecA->y  * vecA->y + vecA->z * vecA->z );
}

void vec3_addTo(vec3 *vecA, vec3* vecB){
    vecA->x += vecB->x;
    vecA->y += vecB->y;
    vecA->z += vecB->z;
}
void vec3_addValTo(vec3 *vecA, float value){
    vecA->x += value;
    vecA->y += value;
    vecA->z += value;
}
void vec3_subFrom(vec3 *vecA, vec3* vecB){
    vecA->x -= vecB->x;
    vecA->y -= vecB->y;
    vecA->z -= vecB->z;
}
void vec3_subValFrom(vec3 *vecA, float value){
    vecA->x -= value;
    vecA->y -= value;
    vecA->z -= value;
}
void vec3_mulTo(vec3 *vecA, vec3* vecB){
    vecA->x *= vecB->x;
    vecA->y *= vecB->y;
    vecA->z *= vecB->z;
}
void vec3_mulValTo(vec3 *vecA, float value){
    vecA->x *= value;
    vecA->y *= value;
    vecA->z *= value;
}
void vec3_divTo(vec3 *vecA, vec3* vecB){
    vecA->x /= vecB->x;
    vecA->y /= vecB->y;
    vecA->z /= vecB->z;
}
void vec3_divValTo(vec3 *vecA, float value){
    vecA->x /= value;
    vecA->y /= value;
    vecA->z /= value;
}

void vec3_set(vec3* vecA, float x, float y, float z){
    vecA->x = x; vecA->y = y; vecA->z = z;
}

vec3 vec3_unitVector(vec3* vecA){
    vec3 ref;
    float l = vec3_length(&ref);
    ref.x = vecA->x / l;ref.y = vecA->y / l;ref.z = vecA->z / l;
    return ref;
}
