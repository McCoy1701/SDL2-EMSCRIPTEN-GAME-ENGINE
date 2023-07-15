#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct WatchState* WatchStatePtr;

typedef struct {
    int hour;
    int minute;
    int second;
} TimeSource;

typedef struct {
    int currentHour;
    int currentMinute;
    int currentSecond;
} Display;

struct WatchState {
    EventStartFunc start;
    EventStopFunc stop;
};

typedef void (*EventStartFunc) (WatchStatePtr);
typedef void (*EventStopFunc) (WatchStatePtr);

void defaultImplementation(WatchStatePtr state);

#endif