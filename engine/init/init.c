#include "init.h"

App app;

void init(void) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	SDL_SetWindowTitle(app.window, "Shitter");
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &app.window, &app.renderer);
	
	initSounds();

	initFont();
	
	srand(time(NULL));
}

void quit(void) {
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
}
