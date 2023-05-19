#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>

#include "../init/init.h"
#include "../structs.h"
#include "../definitions.h"

void initSounds(void);

void loadSounds(char* filename, AudioClip* clip);

void playSound(AudioClip* clip);

#endif