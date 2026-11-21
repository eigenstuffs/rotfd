#ifndef GAME_TIMER_LINKED_LIST_INTERNAL_H
#define GAME_TIMER_LINKED_LIST_INTERNAL_H

#include "Game/handle_list_operations_internal.h"
struct TimerNode {Handle target;int kind;TimerNode*next;float time,period;};
struct TimerList {char unknown00[12];float clock;char unknown10[12];TimerNode*head;};
struct TimerTarget {unsigned long unknown00;Handle handle;};
extern "C" {void fn_80285CDC(TimerList*,TimerNode*);TimerNode*fn_80285D34(TimerList*);void fn_801F7914(Handle*,const Handle*);}

typedef char CheckTimerNode[sizeof(TimerNode)==20?1:-1];
typedef char CheckTimerList[sizeof(TimerList)==32?1:-1];
#endif
