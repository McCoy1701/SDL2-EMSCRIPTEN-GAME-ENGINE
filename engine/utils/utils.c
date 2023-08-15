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
