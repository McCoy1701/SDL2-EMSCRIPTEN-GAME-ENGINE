CC = emcc
CFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]'
LDFLAGS = --bind

GAME_DIR = game
ENGINE_DIR = engine
INIT_DIR = engine/init
DRAW_DIR = engine/draw
EFFECTS_DIR = engine/effects
TEXT_DIR = engine/text
SOUNDS_DIR = engine/sounds
ENTITIES_DIR = game/entities
INPUT_DIR = engine/inputs
TITLE_DIR = game/title
INDEX_DIR=index
SRC_DIR=src
OBJ_DIR=obj

all: $(INDEX_DIR)

$(OBJ_DIR)/init.o: $(INIT_DIR)/init.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/utils.o: $(ENGINE_DIR)/utils.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/draw.o: $(DRAW_DIR)/draw.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/text.o: $(TEXT_DIR)/text.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/sounds.o: $(SOUNDS_DIR)/sound.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/effects.o: $(EFFECTS_DIR)/effects.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/stage.o: $(STAGE_DIR)/stage.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/title.o: $(TITLE_DIR)/title.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/player.o: $(ENTITIES_DIR)/player/player.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/input.o: $(INPUT_DIR)/input.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) $< -c -o $@


$(INDEX_DIR): $(OBJ_DIR)/init.o $(OBJ_DIR)/draw.o $(OBJ_DIR)/sounds.o $(OBJ_DIR)/text.o $(OBJ_DIR)/input.o $(OBJ_DIR)/main.o
	mkdir -p $(INDEX_DIR)
	$(CC) $(OBJ_DIR)/init.o $(OBJ_DIR)/draw.o $(OBJ_DIR)/sounds.o $(OBJ_DIR)/text.o $(OBJ_DIR)/input.o $(OBJ_DIR)/main.o -s WASM=1 $(CFLAGS) --shell-file htmlTemplate/template.html --preload-file assets -o $(INDEX_DIR)/$@.html

clean:
	rm -rf $(INDEX_DIR) $(OBJ_DIR)
	clear

