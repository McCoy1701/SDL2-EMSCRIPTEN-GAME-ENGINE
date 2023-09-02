#include "atlas.h"

extern App app;

static AtlasImage atlases[NUM_ATLAS_BUCKETS];
static SDL_Texture* atlasTexture;

void initAtlas(void) {
    memset(&atlases, 0, sizeof(AtlasImage) * NUM_ATLAS_BUCKETS);
    atlasTexture = IMG_LoadTexture(app.renderer, "atlas.png");
    loadAtlasData();
}

AtlasImage* getAtlasImage(char* filename) {
    AtlasImage* atlas;
    unsigned long i;

    i = hashFunction(filename) % NUM_ATLAS_BUCKETS;

    for (atlas = atlases[i].next; atlas != NULL; atlas = atlas->next) {
        if (strcmp(atlas->filename, filename) == 0) {
            return atlas;
        }
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "No such atlas image '%s'", filename);
    exit(1);

    return NULL;
}

void loadAtlasData(void) {
    AtlasImage* atlasImage, *atlas;
    int x, y, w, h;
    cJSON *root, *node;
    char *text, *filename;
    unsigned long i;

    text = readFile("atlas.json");

    root = cJSON_Parse(text);

    for (node = root->child; node != NULL; node = node->next) {
        filename = cJSON_GetObjectItem(node, "filename")->valuestring;
        x = cJSON_GetObjectItem(node, "x")->valueint;
        y = cJSON_GetObjectItem(node, "y")->valueint;
        w = cJSON_GetObjectItem(node, "w")->valueint;
        h = cJSON_GetObjectItem(node, "h")->valueint;

        i = hashFunction(filename) % NUM_ATLAS_BUCKETS;

        atlas = &atlases[i];

        while (atlas->next) {
            atlas = atlas->next;
        }

        atlasImage = malloc(sizeof(AtlasImage));
        memset(atlasImage, 0, sizeof(AtlasImage));
        atlas->next = atlasImage;

        STRNCPY(atlasImage->filename, filename, MAX_FILENAME_LENGTH);
        atlasImage->rect.x = x;
        atlasImage->rect.y = y;
        atlasImage->rect.w = w;
        atlasImage->rect.h = h;

        atlasImage->texture = atlasTexture;
    }

    cJSON_Delete(root);

    free(text);
}

void setAtlasColor(int r, int g, int b, int a) {
    SDL_SetTextureColorMod(atlasTexture, r, g, b);
    SDL_SetTextureAlphaMod(atlasTexture, a);
}