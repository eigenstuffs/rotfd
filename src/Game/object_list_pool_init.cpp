#include "Game/object_list_pool_internal.h"
extern "C" void fn_80285DB4(ObjectListPool*self){ObjectListNode*node=self->nodes;self->freeNodes=node;for(int i=0;i<2047;++i,++node)node->next=node+1;ObjectListRecord*record=self->records;self->freeRecords=record;for(int i=0;i<1023;++i,++record)record->next=record+1;}
