#include "tiles.h"

AtlasImage* blocks[NUM_OF_BLOCKS];
int tileCount;

void initTiles(void) {
    int i;
    char* buffer, *filename;
    cJSON* root, *node;

    i = 0;

    buffer = readFile("assets/data/tiles.json");

    root = cJSON_Parse(buffer);

    for (node = root->child; node != NULL; node = node->next) {
        filename = cJSON_GetObjectItem(node, "filename")->valuestring;
        blocks[i] = getAtlasImage(filename);
        i++;
    }

    tileCount = i;

    cJSON_Delete(root);
    free(buffer);
    printf("tiles loaded: %d\n", tileCount);
}
