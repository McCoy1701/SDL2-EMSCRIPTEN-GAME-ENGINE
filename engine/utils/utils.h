#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "../definitions.h"

char** tokenizeString(const char* str, const char* delimiter, const char* filename);

char* readFile(char* filename);

unsigned long hashFunction(const char* string);

void toISO(int x, int y, int* sx, int* sy);

#endif