#include "Game/platform_pool_internal.h"
extern "C" void fn_802816D0(PlatformPool_80281EA4* self) {
    for(int i=self->first();i!=-1;i=self->next(i)) {
        PlatformPoolRecord* entry=&self->data[i];
        if(entry->flag50) {
            entry->flag50=0;
        } else {
            entry->object->slot=-1;
            self->release(i);
        }
    }
}
extern "C" void fn_802817C8(PlatformPool_80281EA4* self,int i) {
    PlatformPoolRecord* entry=&self->data[i];
    entry->object->slot=-1;
    self->release(i);
}
