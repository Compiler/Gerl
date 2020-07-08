#include "Ray.h"



vec3 ray_getPositionAt(const ray* currentRay, double t){
    vec3 returnedVec;
    returnedVec.x = currentRay->position.x + t * currentRay->direction.x; 
    returnedVec.y = currentRay->position.y + t * currentRay->direction.y; 
    returnedVec.z = currentRay->position.z + t * currentRay->direction.z; 
    return returnedVec;
}