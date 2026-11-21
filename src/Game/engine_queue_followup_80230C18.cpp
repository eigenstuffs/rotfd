#include "Game/engine_queue_followup.h"

extern "C" void fn_80230C18(EngineFollowupQueue *object) {
    if (!object->dirty && object->cursor && object->values[object->cursor - 1] &&
        fn_801F7EB8(&object->target)) {
        EngineFollowupEntry *entry = &lbl_801E9D24.manager->entries[object->target.index];
        fn_802073E8(object, object->values[object->cursor - 1],
                     entry->tag == object->target.tag ? entry->object : 0,
                     lbl_8037B1D0);
        object->dirty = 1;
    }
}
