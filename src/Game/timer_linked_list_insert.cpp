#include "Game/timer_linked_list_internal.h"
extern "C" void fn_802602B8(TimerList*self,int kind,const TimerTarget*target,float delay,float period){
 TimerNode*node=fn_80285D34(self);node->kind=kind;fn_801F7914(&node->target,&target->handle);node->period=period;node->time=self->clock+delay;
 TimerNode*head=self->head;TimerNode*current=head;TimerNode*previous=0;
 while(current){if(current->time>=node->time)break;previous=current;current=current->next;}
 if(previous){node->next=previous->next;previous->next=node;}else{node->next=head;self->head=node;}
}
