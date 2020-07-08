#include "PPMWriter.h"


void ppm_writeBufferToFile(const ppmBuffer* buffer, const char* filePath){
    FILE* filePointer = fopen(filePath, "w");
    fprintf(filePointer, "P3\n3 2\n255\n");
    for(int i = 0; i < )
    fprintf(filePointer, "%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", buffer);

    fclose(filePointer);
}

