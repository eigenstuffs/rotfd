#include "Game/object_list_pool_internal.h"
extern "C" void fn_80286158(ObjectListGroup*self){ObjectListNode*node=self->firstHead;while(node){ObjectListNode*next=node->next;fn_80285CDC(objectListPool(),node);node=next;}self->firstHead=0;self->firstTail=0;}
extern "C" ObjectListNode*fn_802861C4(){return fn_80285D34(objectListPool());}
extern "C" void fn_802861F0(ObjectListGroup*self){ObjectListRecord*record=self->recordHead;while(record){ObjectListRecord*next=record->next;fn_80285C74(objectListPool(),record);record=next;}self->recordTail=0;self->recordHead=0;}
extern "C" ObjectListRecord*fn_8028625C(){return fn_80285CC0(objectListPool());}
