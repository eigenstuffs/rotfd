#ifndef GAME_CALLBACK_ENTRY_INTERNAL_H
#define GAME_CALLBACK_ENTRY_INTERNAL_H
#include "Game/callback_cycle_internal.h"
struct CallbackEntry {int (CallbackCycle::*callback)(int, DispatchNode*);CallbackEntry *next;};
struct CallbackGroup {int key;CallbackEntry *first,*second;CallbackGroup *next;};
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
CallbackEntry *fn_8025FB2C(CallbackEntry*,int);
}
#endif
