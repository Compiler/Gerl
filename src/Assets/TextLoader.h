#pragma once
#include <stdio.h>
#include <stdlib.h>

#define GERL_INTERNAL "src/Resources"
#define GERL_INTERNAL_SHADERS GERL_INTERNAL "/Shaders/"
char* getTextContents(const char fileName[]);