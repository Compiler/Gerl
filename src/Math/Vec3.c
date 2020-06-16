#include "Vec3.h"


float length(vec3* vecA){
    return sqrt(vecA->x * vecA->x + vecA->y  * vecA->y + vecA->z * vecA->z );
}

void addTo(vec3 *vecA, vec3* vecB){
    vecA->x += vecB->x;
    vecA->y += vecB->y;
    vecA->z += vecB->z;
}
void addTo(vec3 *vecA, float value){
    vecA->x += value;
    vecA->y += value;
    vecA->z += value;
}
void subFrom(vec3 *vecA, vec3* vecB){
    vecA->x -= vecB->x;
    vecA->y -= vecB->y;
    vecA->z -= vecB->z;
}
void subFrom(vec3 *vecA, float value){
    vecA->x -= value;
    vecA->y -= value;
    vecA->z -= value;
}
void mulTo(vec3 *vecA, vec3* vecB){
    vecA->x *= vecB->x;
    vecA->y *= vecB->y;
    vecA->z *= vecB->z;
}
void mulTo(vec3 *vecA, float value){
    vecA->x *= value;
    vecA->y *= value;
    vecA->z *= value;
}
void divTo(vec3 *vecA, vec3* vecB){
    vecA->x /= vecB->x;
    vecA->y /= vecB->y;
    vecA->z /= vecB->z;
}
void divTo(vec3 *vecA, float value){
    vecA->x /= value;
    vecA->y /= value;
    vecA->z /= value;
}

void unitVector(vec3* vecA){
    vec3 ref;
    ref.x = vecA->x;ref.y = vecA->y;ref.z = vecA->z;

}
