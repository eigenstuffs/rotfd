#include "Game/engine_owner_key_lookup.h"

static inline void assign(Handle_801F7F10* to, const Handle_801F7F10& from)
{
    fn_801F86C8(lbl_801E9D24.manager, to, -1);
    to->value = from.value;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}

static inline LookupObject* resolve(const Handle_801F7F10& handle)
{
    LookupEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag == handle.bits.tag ? entry->object : 0;
}

extern "C" int fn_801FE6BC(LookupOwner* self, int key,
    Handle_801F7F10* first, Handle_801F7F10* second, Handle_801F7F10* related)
{
    assign(first, LookupHandle5());
    assign(second, LookupHandle3());
    assign(related, LookupHandle2());
    for (int i = 0; i < self->count; ++i) {
        LookupObject* object = resolve(*(Handle_801F7F10*)(self->handlesBytes + i * 4));
        if (object && fn_801F7EB8(&object->related)) {
            for (int j = 0; j < object->count; ++j) {
                if (fn_801F7EB8((Handle_801F7F10*)(object->handlesBytes + j * 4)) &&
                    key == resolve(*(Handle_801F7F10*)(object->handlesBytes + j * 4))->key() &&
                    fn_801F7EB8(&object->related)) {
                    assign(first, object->first[j]);
                    assign(second, object->second[j]);
                    assign(related, object->related);
                    return 1;
                }
            }
        }
    }
    return 0;
}
