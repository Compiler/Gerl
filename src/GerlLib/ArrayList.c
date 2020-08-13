#include "ArrayList.h"


ArrayList* ArrayList_create(size_t elementSize){
    ArrayList* list = malloc(sizeof(ArrayList));
    list->size = 0;
    list->currentMultiple = 4;
    list->elementSize = elementSize;
    list->data = calloc(list->currentMultiple, list->elementSize);
    GERL_DEBUG("array list created with %d sized elements\n", elementSize);
    return list;
}


void ArrayList_add(ArrayList* array, void* item){
    assert(array != NULL);
    const void* source = (const void*)item;

    void* destination = &array->data[0] + (array->size * array->elementSize);
    GERL_DEBUG("Adding element with size %d from %d to %d\n", array->elementSize, source, destination);
    memmove(destination, source, array->elementSize);
    
}
void* ArrayList_get(ArrayList* array, int index){
    assert(array != NULL);
    return &array->data[index];
}

size_t ArrayList_getSize(const ArrayList* array){
    assert(array != NULL);
    return array->size;
}
char ArrayList_isEmpty(const ArrayList* array){
    assert(array != NULL);
    return array->size == 0;
}

void ArrayList_remove(ArrayList* array, void* item);