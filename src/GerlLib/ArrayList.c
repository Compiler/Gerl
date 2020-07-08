#include "ArrayList.h"


ArrayList* ArrayList_create(){
    ArrayList* list = malloc(sizeof(ArrayList));
    list->size = 0;
    list->data = calloc(4, sizeof(void*));
    return list;
}


void ArrayList_add(ArrayList* array, void* item){
    printf("Size of item %d\n", sizeof(void*));

}
void* ArrayList_get(ArrayList* array, int index){
    return array + (index * sizeof(void*));

}
void ArrayList_remove(ArrayList* array, void* item);