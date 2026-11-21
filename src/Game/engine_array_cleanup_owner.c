#include "Game/engine_array_cleanup.h"

static inline void destroy28(struct EngineCleanupArray28* self) {
    int i;
    if(self) {
        if(self->items) {
            for(i=0;i<self->count;i++){}
            if(self->items){fn_8028FD50(lbl_8028F698,self->items,self->capacity*28);self->items=0;}
            self->items=0;
        }
    }
}
static inline void destroy2(struct EngineCleanupArray2* self) {
    int i;
    if(self) {
        if(self->items) {
            for(i=0;i<self->count;i++){}
            if(self->items){fn_8028FD50(lbl_8028F698,self->items,self->capacity*2);self->items=0;}
            self->items=0;
        }
    }
}
struct EngineCleanupOwner* fn_802499CC(struct EngineCleanupOwner* self,short deleting) {
    if(self) {
        self->vptr08=lbl_802EC268;
        destroy28(&self->second);destroy2(&self->first);
        __dt__22SpatialRecord_802EA440Fv(self,0);
        if(deleting>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
