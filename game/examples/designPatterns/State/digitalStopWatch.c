#include "digitalStopWatch.h"

struct DigitalStopWatch {
    WatchStatePtr state;
    TimeSource source;
    Display watchDisplay;
};

DigitalStopWatchPtr createWatch(void) {
    DigitalStopWatchPtr instance = malloc(sizeof *instance);

    if (NULL != instance) {
        transitionToStopped(&instance->state);
    }
    return instance;
}

void destroyWatch(DigitalStopWatchPtr instance) {
    free(instance);
}

void startWatch(DigitalStopWatchPtr instance) {
    instance->state->start(&instance->state);
}

void stopWatch(DigitalStopWatchPtr instance) {
    instance->state->stop(&instance->state);
}

void changeState(DigitalStopWatchPtr instance, WatchStatePtr newState) {
    instance->state = newState;
}




