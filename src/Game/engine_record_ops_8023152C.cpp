// Original queue operations; see docs/notes/game-engine-record-ops.md.
#include "Game/engine_record_ops_queue.h"

extern "C" int fn_8023152C(EngineGroupQueue *object,int group) {
    if(!object->finished[group] && object->cursor[group]==object->count[group])object->finished[group]=1;
    if(object->finished[group])return 0;
    object->slot2C(&object->handles[group][object->cursor[group]],group);
    object->cursor[group]++;
    object->dirty[group]=0;
    return 1;
}
