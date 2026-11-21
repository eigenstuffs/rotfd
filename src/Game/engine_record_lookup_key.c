#include "Game/engine_record_lookup.h"

static inline int equal(const struct EngineRecordLookupObject* object, const struct EngineRecordLookupKey* key)
{
    return object->key.value == key->value;
}

int fn_8024A86C(struct EngineRecordLookupOwner* self, const struct EngineRecordLookupKey* key)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (fn_801F7EB8(&self->items[i]) && equal(engineRecordLookupResolve(&self->items[i]), key))
            return i;
    }
    return -1;
}
