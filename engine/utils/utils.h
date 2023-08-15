#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

char** tokenizeString(const char* str, const char* delimiter, const char* filename);

#endif