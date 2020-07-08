#ifndef GERL_ARRAYLIST_H
#define GERL_ARRAYLIST_H
#pragma once

typedef struct _arraylist{
    size_t size;
    void** data;
}ArrayList;

ArrayList* ArrayList_create();
ArrayList* ArrayList_createSized(int initialSize);







#endif
