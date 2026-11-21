#ifndef GAME_CALLBACK_CYCLE_INTERNAL_H
#define GAME_CALLBACK_CYCLE_INTERNAL_H
// Private views of the observed linked callback state; field names are provisional.
typedef unsigned long u32;
struct CallbackCycle;
struct DispatchNode {
 u32 unknown0;
 int (CallbackCycle::*callback)(int, DispatchNode *);
 char unknown10[0xc];
 DispatchNode *next;
 char unknown20[8];
 unsigned short flags, count;
};
struct SelectedNode {u32 unknown;int key;SelectedNode *next;u32 unknownC;float time;};
struct CallbackCycle {
 char unknown0[0xc];signed char reset;char unknownD[3];DispatchNode *head;u32 unknown14;
 SelectedNode *active,*activeTail,*pending,*pendingTail;u32 handle;float time;int key;char unknown34[0xc];u32 state;
 inline DispatchNode *next();
};
extern "C" {extern DispatchNode *lbl_80378088;void fn_80286158(CallbackCycle*);void fn_8025F240(DispatchNode*,CallbackCycle*);void fn_801F7914(u32*,SelectedNode*);}
#endif
