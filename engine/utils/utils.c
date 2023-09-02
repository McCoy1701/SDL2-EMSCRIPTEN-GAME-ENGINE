#include "utils.h"

char** tokenizeString(const char* str, const char* delimiter, const char* filename) {
    int numOfStrings = 4;

    char** tokens = (char**)malloc((numOfStrings * sizeof(char*)));
    memset(tokens, 0, (numOfStrings * sizeof(char*)));
    
    char* tempStr = malloc(strlen(str));
    memset(tempStr, 0, strlen(str));
    
    strcpy(tempStr, str);
    
    char* token = strtok(tempStr, delimiter);

    for (int i = 0; token != NULL; i++) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        token = strtok(NULL, delimiter);
    }

    free(tempStr);
    free(token);

    return tokens;
}

unsigned long hashFunction(const char* string) {
    unsigned long hash = 5381;
    int c;
    c = *string;

    while (c) {
        hash = ((hash << 5) + hash) + c;
        c = *string++;
    }

    hash = ((hash << 5) + hash);
    
    return hash;
}

char* readFile(char* filename) {
    char* buffer;
    long length;
    FILE* file;

    file = fopen(filename, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);

        buffer = malloc(length);
        memset(buffer, 0, length);
        fread(buffer, 1, length, file);

        fclose(file);
    }

    return buffer;
}


void toISO(int x, int y, int* sx, int* sy) {
	*sx = MAP_OFFSET_X + ((x * TILE_WIDTH / 2) + (y * TILE_WIDTH / 2));
	*sy = MAP_OFFSET_Y + ((y * TILE_HEIGHT / 2) - (x * TILE_HEIGHT / 2));
}

