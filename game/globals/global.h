#ifndef GLOBAL_H
#define GLOBAL_H

#include "../../engine/init/init.h"
#include "../../engine/atlas/atlas.h"
#include "../../engine/draw/draw.h"
#include "../../engine/sounds/sound.h"
#include "../../engine/text/text.h"
#include "../../engine/inputs/input.h"
#include "../../engine/utils/utils.h"
#include "../../engine/utils/deltaTime/deltaTime.h"
#include "../../engine/animations/animation.h"
#include "../../engine/entities/entities.h"

#include "../../engine/definitions.h"
#include "../../engine/structs.h"
#include "../../engine/ui/ui.h"

#include "globalEnums.h"

extern AtlasImage* blocksArray[NUM_OF_BLOCKS];
extern AtlasImage* concreteArray[NUM_OF_BLOCKS];
extern AtlasImage* decorationsArray[NUM_OF_BLOCKS];
extern AtlasImage* entitiesArray[NUM_OF_BLOCKS];
extern AtlasImage* fenceArray[NUM_OF_BLOCKS];
extern AtlasImage* glassArray[NUM_OF_BLOCKS];
extern AtlasImage* grassArray[NUM_OF_BLOCKS];
extern AtlasImage* oreArray[NUM_OF_BLOCKS];
extern AtlasImage* plantsArray[NUM_OF_BLOCKS];
extern AtlasImage* redstoneArray[NUM_OF_BLOCKS];
extern AtlasImage* slabsArray[NUM_OF_BLOCKS];
extern AtlasImage* stairsArray[NUM_OF_BLOCKS];
extern AtlasImage* stoneArray[NUM_OF_BLOCKS];
extern AtlasImage* terracottaArray[NUM_OF_BLOCKS];
extern AtlasImage* wallArray[NUM_OF_BLOCKS];
extern AtlasImage* woodArray[NUM_OF_BLOCKS];
extern AtlasImage* woolArray[NUM_OF_BLOCKS];

extern AtlasImage* uiArray[NUM_OF_UI_ITEMS];

extern int tileCount;
extern int uiCount;

extern int blockCount;
extern int concreteCount;
extern int decorationsCount;
extern int entitiesCount;
extern int fenceCount;
extern int glassCount;
extern int grassCount;
extern int oreCount;
extern int plantsCount;
extern int redstoneCount;
extern int slabsCount;
extern int stairsCount;
extern int stoneCount;
extern int terracottaCount;
extern int wallCount;
extern int woodCount;
extern int woolCount;


#endif