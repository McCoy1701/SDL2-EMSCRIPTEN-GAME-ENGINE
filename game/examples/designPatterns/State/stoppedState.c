#include "stoppedState.h"
#include "startedState.h"

static startWatch(WatchStatePtr state) {
    transitionToStarted(state);
}

void transitionToStopped(WatchStatePtr state) {
    defaultImplementation(state);
    state->start = startWatch;
}
