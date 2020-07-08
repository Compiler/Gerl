#include "ArrayList.h"


ArrayList* ArrayList_create(){
    ArrayList* list = malloc(sizeof(ArrayList));
    list->size = 0;
    list->currentMultiple = 4;
    list->data = calloc(list->currentMultiple, sizeof(void*));
    return list;
}


void ArrayList_add(ArrayList* array, void* item){
    printf("Size of item %d\n", sizeof(void*));
    array->data[array->size++] = *item; //fix this ... idk how and im tired thxx
}
void* ArrayList_get(ArrayList* array, int index){
    return array->data[index];

}
void ArrayList_remove(ArrayList* array, void* item);