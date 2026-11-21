#ifndef GAME_CALLBACK_KEY_INTERNAL_H
#define GAME_CALLBACK_KEY_INTERNAL_H
#include "Game/callback_cycle_internal.h"
// Observed key array view; the second word of each key record is unknown.
typedef int (CallbackCycle::*CycleCallback)(int, DispatchNode *);
struct DispatchKey {int key;u32 unknown;};
struct DispatchKeyView {
 u32 unknown0;CycleCallback callback;
 int length;u32 capacity;DispatchKey *links;DispatchKeyView *next;
 char unknown20[8];unsigned short flags,count;
};
#endif
