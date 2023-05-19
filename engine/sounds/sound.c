#include "sound.h"

AudioClip playerSnd;

void initSounds(void) {
    loadSounds("assets/soundEffects/laser1.wav", &playerSnd);
    
    app.deviceID = SDL_OpenAudioDevice(NULL, 0, &(playerSnd.spec), NULL, 0);

    if (app.deviceID == 0) {
        printf("failed to load device id %s\n", SDL_GetError());
    }
    
    SDL_PauseAudioDevice(app.deviceID, 0);
}

void loadSounds(char* filename, AudioClip* clip) {
    printf("loading sounds\n");
    
    STRNCPY(clip->filename, filename, sizeof(char));

    if(SDL_LoadWAV(filename, &(clip->spec), &(clip->buffer), &(clip->length)) == NULL) {
        printf("Error loading: %s\n", filename);
    }
}

void playSound(AudioClip* clip) {
    int success = SDL_QueueAudio(app.deviceID, clip->buffer, clip->length);
    if (success < 0) {
        printf("couldn't play sound: %s Error: %s\n", clip->filename, SDL_GetError());
    }
}
