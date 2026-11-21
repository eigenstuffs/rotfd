#include "Game/object_list_pool_internal.h"
extern "C" void fn_80285CDC(ObjectListPool*self,ObjectListNode*node){node->next=self->freeNodes;self->freeNodes=node;{ObjectListEmptyHandle empty;fn_801F7914(&node->handle,&empty);}}
