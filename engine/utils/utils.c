#include "utils.h"

char** tokenizeString(const char* str, const char* delimiter) {
    char** tokens = malloc(5 * sizeof(char*));

    char* tempStr = malloc(strlen(str));
    strcpy(tempStr, str);
    
    char* token = strtok(tempStr, delimiter);

    for ( int i = 0; token != NULL; i++) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        token = strtok(NULL, delimiter);
    }

    free(tempStr);

    return tokens;
}