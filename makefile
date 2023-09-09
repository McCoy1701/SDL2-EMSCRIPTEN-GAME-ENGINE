ECC = emcc
CC = gcc

EFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'
CFLAGS =  -lSDL2 -lSDL2_image -lm
LDFLAGS = --bind

ENGINE_DIR = engine
ANIMATION_DIR = engine/animations
ATLAS_DIR = engine/atlas
DRAW_DIR = engine/draw
EFFECTS_DIR = engine/effects
ENTITIES_DIR = engine/entities
INIT_DIR = engine/init
INPUT_DIR = engine/inputs
JSON_DIR = engine/json
SOUNDS_DIR = engine/sounds
SPRITES_DIR = engine/sprites
TEXT_DIR = engine/text
TOOLS_DIR = engine/tools
UI_DIR = engine/ui
UTILS_DIR = engine/utils

GAME_DIR = game

SRC_DIR=src

OBJ_DIR=obj
INDEX_DIR=index

.PHONY: all clean always atlasGen

all: $(INDEX_DIR)

$(OBJ_DIR)/animation.o: $(ANIMATION_DIR)/animation.c 
	$(ECC) $< -c -o $@

$(OBJ_DIR)/animationNode.o: $(ANIMATION_DIR)/animationNode.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/atlas.o: $(ATLAS_DIR)/atlas.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/_drawInteral.o: $(DRAW_DIR)/_drawInteral.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/draw.o: $(DRAW_DIR)/draw.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/drawShapes.o: $(DRAW_DIR)/drawShapes.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/entities.o: $(ENTITIES_DIR)/entities.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/init.o: $(INIT_DIR)/init.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/input.o: $(INPUT_DIR)/input.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/eJSON.o: $(JSON_DIR)/cJSON.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/sounds.o: $(SOUNDS_DIR)/sound.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/text.o: $(TEXT_DIR)/text.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/ui.o: $(UI_DIR)/ui.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/deltaTime.o: $(UTILS_DIR)/deltaTime/deltaTime.c
	$(ECC) $< -c -o $@	

$(OBJ_DIR)/vector2.o: $(UTILS_DIR)/vector/vector2.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/vector3.o: $(UTILS_DIR)/vector/vector3.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/utils.o: $(UTILS_DIR)/utils.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/generateWorld.o: $(GAME_DIR)/world/generateWorld.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/game.o: $(GAME_DIR)/game.c
	$(ECC) $< -c -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(ECC) $< -c -o $@


$(INDEX_DIR): always $(OBJ_DIR)/animation.o $(OBJ_DIR)/animationNode.o $(OBJ_DIR)/atlas.o $(OBJ_DIR)/_drawInteral.o $(OBJ_DIR)/draw.o $(OBJ_DIR)/drawShapes.o $(OBJ_DIR)/entities.o $(OBJ_DIR)/init.o $(OBJ_DIR)/input.o $(OBJ_DIR)/eJSON.o $(OBJ_DIR)/sounds.o $(OBJ_DIR)/text.o $(OBJ_DIR)/ui.o $(OBJ_DIR)/deltaTime.o $(OBJ_DIR)/vector2.o $(OBJ_DIR)/vector3.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/generateWorld.o $(OBJ_DIR)/game.o $(OBJ_DIR)/main.o
	mkdir -p $(INDEX_DIR)
	$(ECC) $(OBJ_DIR)/animation.o $(OBJ_DIR)/animationNode.o $(OBJ_DIR)/atlas.o $(OBJ_DIR)/_drawInteral.o $(OBJ_DIR)/draw.o $(OBJ_DIR)/drawShapes.o $(OBJ_DIR)/entities.o $(OBJ_DIR)/init.o $(OBJ_DIR)/input.o $(OBJ_DIR)/eJSON.o $(OBJ_DIR)/sounds.o $(OBJ_DIR)/text.o $(OBJ_DIR)/ui.o $(OBJ_DIR)/deltaTime.o $(OBJ_DIR)/vector2.o $(OBJ_DIR)/vector3.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/generateWorld.o $(OBJ_DIR)/game.o $(OBJ_DIR)/main.o -s WASM=1 $(EFLAGS) --shell-file htmlTemplate/template.html --preload-file assets -o $(INDEX_DIR)/$@.html

atlasGen: always
	$(CC) $(JSON_DIR)/cJSON.c $(TOOLS_DIR)/atlasGen.c -o $(OBJ_DIR)/atlasGen.o $(CFLAGS)

clean:
	rm -rf $(INDEX_DIR) $(OBJ_DIR)
	clear

always:
	mkdir -p $(OBJ_DIR)
