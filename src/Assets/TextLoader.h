#ifndef TEXTLOADER_H
#define TEXTLOADER_H
#pragma once
#include <stdio.h>
#include <stdlib.h>

#define GERL_INTERNAL(x) "src/Resources" x
#define GERL_INTERNAL_SHADERS(x) GERL_INTERNAL() "/Shaders/" x

char* getTextContents(const char fileName[]);
#endif