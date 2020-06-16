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

void vec3_unitVector(vec3* vecA){
    vec3 ref;
    ref.x = vecA->x;ref.y = vecA->y;ref.z = vecA->z;

}
