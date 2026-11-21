#include "Game/callback_cycle_internal.h"
struct CallbackClock {char unknown0[0xc];float value;};
struct CallbackGlobals {char unknown0[0x124];CallbackClock *clock;};
extern "C" {
extern CallbackGlobals lbl_801E9D24;
SelectedNode *fn_802861C4(CallbackCycle*);
}
extern "C" void fn_8025EAB0(CallbackCycle *self,int key,SelectedNode *handle,float time){
 SelectedNode *node=fn_802861C4(self);
 node->key=key;
 fn_801F7914(&node->unknown,handle);
 *(float*)&node->unknownC=lbl_801E9D24.clock->value;
 node->time=time;
 if(self->pendingTail)self->pendingTail->next=node;
 else self->pending=node;
 self->pendingTail=node;
 node->next=0;
 if((int)self->state!=2)self->state=3;
}
