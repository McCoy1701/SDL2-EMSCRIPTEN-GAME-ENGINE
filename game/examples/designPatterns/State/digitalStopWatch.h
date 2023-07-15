#ifndef DIGITAL_STOP_WATCH_H
#define DIGITAL_STOP_WATCH_H

#include "watchState.h"
#include "startedState.h"
#include "stoppedState.h"

typedef struct DigitalStopWatch* DigitalStopWatchPtr;

DigitalStopWatchPtr createWatch(void);

void destroyWatch(DigitalStopWatchPtr instance);

void startWatch(DigitalStopWatchPtr instance);

void stopWatch(DigitalStopWatchPtr instance);

void changeState(DigitalStopWatchPtr instance, WatchStatePtr newState);

#endif