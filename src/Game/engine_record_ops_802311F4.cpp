// Original queue operations; see docs/notes/game-engine-record-ops.md.
#include "Game/engine_record_ops_queue.h"

extern "C" void fn_802311F4(EngineGroupQueue *object,const unsigned int *source,int value,int group) {
    fn_801F7914(&object->handles[group][object->count[group]],source);
    object->values[group][object->count[group]]=value;
    object->count[group]++;
}

extern "C" void fn_8023127C(EngineGroupQueue *object,const unsigned int *source,int value,int group) {
    object->slot3C(group,0);
    object->slot34(source,value,group);
    object->slot2C(source,group);
    object->cursor[group]++;
}
