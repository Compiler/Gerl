#ifndef GERL_ARRAYLIST_H
#define GERL_ARRAYLIST_H
#pragma once
#include <stdlib.h>

typedef struct _arraylist{
    size_t size;
    size_t currentMultiple;
    void** data;
}ArrayList;

ArrayList* ArrayList_create();


void ArrayList_add(ArrayList* array, void* item);
void* ArrayList_get(ArrayList* array, int index);
void ArrayList_remove(ArrayList* array, void* item);






#endif
