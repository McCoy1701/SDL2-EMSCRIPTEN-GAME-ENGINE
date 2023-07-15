#include "watchState.h"

static void defaultStop(WatchStatePtr state) {

}

static void defaultStart(WatchStatePtr state) {

}

void defaultImplementation(WatchStatePtr state) {
    state->start = defaultStart;
    state->stop  = defaultStop;
}


