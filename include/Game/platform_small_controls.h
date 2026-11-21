#ifndef GAME_PLATFORM_SMALL_CONTROLS_H
#define GAME_PLATFORM_SMALL_CONTROLS_H

struct TimerList;
struct SixHandleResource_802EA840;

extern "C" {
void fn_80275B54();
void fn_8027639C(void*, short port);
void fn_80260180(TimerList*);
void fn_80271944(SixHandleResource_802EA840*);
signed char fn_802719CC(SixHandleResource_802EA840*);
}

#endif
