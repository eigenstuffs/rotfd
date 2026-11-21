// Original queue operations; see docs/notes/game-engine-record-ops.md.
#include "Game/engine_record_ops_queue.h"

extern "C" void fn_80230CE8(EngineQueue *object,const unsigned int *source,int value) {
    fn_801F7914(&object->handles[object->count],source);
    object->values[object->count]=value;
    object->count++;
}

extern "C" void fn_80230D4C(EngineQueue *object,const unsigned int *source,int value,int group) {
    object->slot20(0,0);
    object->slot34(source,value,group);
    object->slot2C(source,group);
    object->cursor++;
}
