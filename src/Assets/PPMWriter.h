#ifndef PPMWRITER_H
#define PPMWRITER_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#ifndef GERL_INTERNAL
#define GERL_INTERNAL(x) "src/Resources" x
#endif
#define GERL_INTERNAL_TEXTURES(x) GERL_INTERNAL() "/Textures/" x

typedef struct PPMBuffer{
    char* buffer;
}ppmBuffer;



void ppm_writeBufferToFile(const PPMBuffer* buffer, const char* filePath);







#endif