#include "startedState.h"
#include "stoppedState.h"

static void stopWatch(WatchStatePtr state) {
    transitionToStopped(state);
}

void transitionToStarted(WatchStatePtr state) {
    defaultImplementation(state);
    state->stop = stopWatch;
}

WatchStatePtr transitionToStarted(void) {
    static struct WatchState startedState;
    static int initialized = 0;

    if (initialized == 0) {
        defaultImplementation(&startedState);
        startedState.stop = stopWatch;

        initialized = 1;
    }
    
    return &startedState;
}
