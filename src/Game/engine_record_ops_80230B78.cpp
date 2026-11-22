#include "Game/engine_record_ops_queue.h"

extern "C" int fn_80230B78(EngineQueue *object,int group) {
    if(!object->finished && object->cursor==object->count)object->finished=1;
    if(object->finished)return 0;
    object->slot2C(&object->handles[object->cursor],group);
    object->cursor++;
    object->dirty=0;
    return 1;
}
