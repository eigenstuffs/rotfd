#include "Game/object_list_pool_internal.h"
extern "C" void fn_80285C74(ObjectListPool*self,ObjectListRecord*record){fn_8025F7FC(record);record->next=self->freeRecords;self->freeRecords=record;}
extern "C" ObjectListRecord*fn_80285CC0(ObjectListPool*self){ObjectListRecord*record=self->freeRecords;self->freeRecords=record->next;record->next=0;return record;}
