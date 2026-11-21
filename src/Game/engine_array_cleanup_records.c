#include "Game/engine_array_cleanup.h"

struct EngineCleanupArray16* fn_8024D3AC(struct EngineCleanupArray16* self,short deleting) {
    int i;
    if(self) {
        if(self->items) {
            for(i=0;i<self->count;i++)fn_801D4BDC(&self->items[i],-1);
            if(self->items) {fn_8028FD50(lbl_8028F698,self->items,self->capacity*16);self->items=0;}
            self->items=0;
        }
        if(deleting>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
