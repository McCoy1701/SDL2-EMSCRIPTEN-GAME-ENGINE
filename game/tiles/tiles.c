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

AtlasImage* uiArray[NUM_OF_UI_ITEMS];

int tileCount;
int uiCount;

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
    
    uiCount          = 0;

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
        blocksArray[blockCount] = getAtlasImage(filename);
        printf("BLOCKS: %d | filename: %s\n", blockCount, filename);
        blockCount++;
    }
        
    else if (strcmp(type, "concrete") == 0) {
        concreteArray[concreteCount] = getAtlasImage(filename);
        printf("CONCRETE: %d | filename: %s\n", concreteCount, filename);
        concreteCount++;
    }

    else if (strcmp(type, "decorations") == 0) {
        decorationsArray[decorationsCount] = getAtlasImage(filename);
        printf("DECORATIONS: : %d | filename: %s\n", decorationsCount, filename);
        decorationsCount++;
    }

    else if (strcmp(type, "entities") == 0) {
        entitiesArray[entitiesCount] = getAtlasImage(filename);
        printf("ENTITIES: %d | filename: %s\n", entitiesCount, filename);
        entitiesCount++;
    }

    else if (strcmp(type, "fence") == 0) {
        fenceArray[fenceCount] = getAtlasImage(filename);
        printf("FENCE: %d | filename: %s\n", fenceCount, filename);
        fenceCount++;
    }

    else if (strcmp(type, "glass") == 0) {
        glassArray[glassCount] = getAtlasImage(filename);
        printf("GLASS: %d | filename: %s\n", glassCount, filename);
        glassCount++;
    }

    else if (strcmp(type, "grass") == 0) {
        grassArray[grassCount] = getAtlasImage(filename);
        printf("GRASS: %d | filename: %s\n", grassCount, filename);
        grassCount++;
    }

    else if (strcmp(type, "ore") == 0) {
        oreArray[oreCount] = getAtlasImage(filename);
        printf("ORE: %d | filename: %s\n", oreCount, filename);
        oreCount++;
    }

    else if (strcmp(type, "plants") == 0) {
        plantsArray[plantsCount] = getAtlasImage(filename);
        printf("PLANTS: %d | filename: %s\n", plantsCount, filename);
        plantsCount++;
    }

    else if (strcmp(type, "redstone") == 0) {
        redstoneArray[redstoneCount] = getAtlasImage(filename);
        printf("REDSTONE: %d | filename: %s\n", redstoneCount, filename);
        redstoneCount++;
    }

    else if (strcmp(type, "slabs") == 0) {
        slabsArray[slabsCount] = getAtlasImage(filename);
        printf("SLABS: %d | filename: %s\n", slabsCount, filename);
        slabsCount++;
    }

    else if (strcmp(type, "stairs") == 0) {
        stairsArray[stairsCount] = getAtlasImage(filename);
        printf("STAIRS: %d | filename: %s\n", stairsCount, filename);
        stairsCount++;
    }

    else if (strcmp(type, "stone") == 0) {
        stoneArray[stoneCount] = getAtlasImage(filename);
        printf("STONE: %d | filename: %s\n", stoneCount, filename);
        stoneCount++;
    }

    else if (strcmp(type, "terracotta") == 0) {
        terracottaArray[terracottaCount] = getAtlasImage(filename);
        printf("TERRACOTTA: %d | filename: %s\n", terracottaCount, filename);
        terracottaCount++;
    }

    else if (strcmp(type, "wall") == 0) {
        wallArray[wallCount] = getAtlasImage(filename);
        printf("WALL: %d | filename: %s\n", wallCount, filename);
        wallCount++;
    }

    else if (strcmp(type, "wood") == 0) {
        woodArray[woodCount] = getAtlasImage(filename);
        printf("WOOD: %d | filename: %s\n", woodCount, filename);
        woodCount++;
    }

    else if (strcmp(type, "wool") == 0) {
        woolArray[woolCount] = getAtlasImage(filename);
        printf("WOOL: %d | filename: %s\n", woolCount, filename);
        woolCount++;
    }

    else if (strcmp(type, "ui") == 0) {
        uiArray[uiCount] = getAtlasImage(filename);
        printf("UI: %d | filename: %s\n", uiCount, filename);
        uiCount++;
    }
}
