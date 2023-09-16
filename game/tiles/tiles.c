#include "tiles.h"

AtlasImage* blocksArray[NUM_OF_BLOCKS];
AtlasImage* concreteArray[NUM_OF_BLOCKS];
AtlasImage* decorationsArray[NUM_OF_BLOCKS];
AtlasImage* entitiesArray[NUM_OF_BLOCKS];
AtlasImage* fenceArray[NUM_OF_BLOCKS];
AtlasImage* glassArray[NUM_OF_BLOCKS];
AtlasImage* grassArray[NUM_OF_BLOCKS];
AtlasImage* oreArray[NUM_OF_BLOCKS];
AtlasImage* plantsArray[NUM_OF_BLOCKS];
AtlasImage* redstoneArray[NUM_OF_BLOCKS];
AtlasImage* slabsArray[NUM_OF_BLOCKS];
AtlasImage* stairsArray[NUM_OF_BLOCKS];
AtlasImage* stoneArray[NUM_OF_BLOCKS];
AtlasImage* terracottaArray[NUM_OF_BLOCKS];
AtlasImage* wallArray[NUM_OF_BLOCKS];
AtlasImage* woodArray[NUM_OF_BLOCKS];
AtlasImage* woolArray[NUM_OF_BLOCKS];

int tileCount;

int blockCount;
int concreteCount;
int decorationsCount;
int entitiesCount;
int fenceCount;
int glassCount;
int grassCount;
int oreCount;
int plantsCount;
int redstoneCount;
int slabsCount;
int stairsCount;
int stoneCount;
int terracottaCount;
int wallCount;
int woodCount;
int woolCount;

void initTiles(void) {
    int i;
    char* buffer, *filename, *type;
    cJSON* root, *node;

    i = 0;

    blockCount       = 0;
    concreteCount    = 0;
    decorationsCount = 0;
    entitiesCount    = 0;
    fenceCount       = 0;
    glassCount       = 0;
    grassCount       = 0;
    oreCount         = 0;
    plantsCount      = 0;
    redstoneCount    = 0;
    slabsCount       = 0;
    stairsCount      = 0;
    stoneCount       = 0;
    terracottaCount  = 0;
    wallCount        = 0;
    woodCount        = 0;
    woolCount        = 0;

    buffer = readFile("assets/data/tiles.json");

    root = cJSON_Parse(buffer);

    for (node = root->child; node != NULL; node = node->next) {
        filename = cJSON_GetObjectItem(node, "filename")->valuestring;
        type     = cJSON_GetObjectItem(node, "typeName")->valuestring;

        loadArrays(i, type, filename);

        i++;
    }

    tileCount = i;

    cJSON_Delete(root);
    free(buffer);
    printf("tiles loaded: %d\n", tileCount);
    
    printf("blockCount: %d, concreteCount: %d, decorationsCount: %d, entitiesCount: %d, fenceCount: %d, glassCount: %d\n", 
            blockCount, concreteCount, decorationsCount, entitiesCount, fenceCount, glassCount);
    printf("grassCount: %d, oreCount: %d, plantsCount: %d,redstoneCount: %d, slabsCount: %d, stairsCount: %d, stoneCount: %d\n",
            grassCount, oreCount,plantsCount, redstoneCount, slabsCount, stairsCount, stoneCount);
    printf("terracottaCount: %d, wallCount: %d, woodCount: %d, woolCount: %d \n",terracottaCount, wallCount,woodCount, woolCount);
}

static void loadArrays(int i, char* type, char* filename) {
    if (strcmp(type, "blocks") == 0) {
            blocksArray[i] = getAtlasImage(filename);
            blockCount++;
        }
        
        if (strcmp(type, "concrete") == 0) {
            concreteArray[i] = getAtlasImage(filename);
            concreteCount++;
        }

        if (strcmp(type, "decorations") == 0) {
            decorationsArray[i] = getAtlasImage(filename);
            decorationsCount++;
        }

        if (strcmp(type, "entities") == 0) {
            entitiesArray[i] = getAtlasImage(filename);
            entitiesCount++;
        }

        if (strcmp(type, "fence") == 0) {
            fenceArray[i] = getAtlasImage(filename);
            fenceCount++;
        }

        if (strcmp(type, "glass") == 0) {
            glassArray[i] = getAtlasImage(filename);
            glassCount++;
        }

        if (strcmp(type, "grass") == 0) {
            grassArray[i] = getAtlasImage(filename);
            grassCount++;
        }

        if (strcmp(type, "ore") == 0) {
            oreArray[i] = getAtlasImage(filename);
            oreCount++;
        }

        if (strcmp(type, "plants") == 0) {
            plantsArray[i] = getAtlasImage(filename);
            plantsCount++;
        }

        if (strcmp(type, "redstone") == 0) {
            redstoneArray[i] = getAtlasImage(filename);
            redstoneCount++;
        }

        if (strcmp(type, "slabs") == 0) {
            slabsArray[i] = getAtlasImage(filename);
            slabsCount++;
        }

        if (strcmp(type, "stairs") == 0) {
            stairsArray[i] = getAtlasImage(filename);
            stairsCount++;
        }

        if (strcmp(type, "stone") == 0) {
            stoneArray[i] = getAtlasImage(filename);
            stoneCount++;
        }

        if (strcmp(type, "terracotta") == 0) {
            terracottaArray[i] = getAtlasImage(filename);
            terracottaCount++;
        }

        if (strcmp(type, "wall") == 0) {
            wallArray[i] = getAtlasImage(filename);
            wallCount++;
        }

        if (strcmp(type, "wood") == 0) {
            woodArray[i] = getAtlasImage(filename);
            woodCount++;
        }

        if (strcmp(type, "wool") == 0) {
            woolArray[i] = getAtlasImage(filename);
            woolCount++;
        }
}
