#ifndef GERL_ARRAYLIST_H
#define GERL_ARRAYLIST_H
#pragma once
#include <stdlib.h>
#include <Logger/GerlLogger.h>
#include <assert.h>
// Array list that takes ownership of item
typedef struct _arraylist{
    size_t size;
    size_t currentMultiple;
    size_t elementSize;
    char* data;
}ArrayList;

ArrayList* ArrayList_create(size_t elementSize);


void ArrayList_add(ArrayList* array, void* item);
void* ArrayList_get(ArrayList* array, int index);
void ArrayList_remove(ArrayList* array, void* item);

size_t ArrayList_getSize(const ArrayList* array);
char ArrayList_isEmpty(const ArrayList* array);




#endif
