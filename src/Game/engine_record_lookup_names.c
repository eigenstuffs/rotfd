#include "Game/engine_record_lookup.h"

int fn_8024A094(struct EngineRecordLookupOwner* self, const char* name, int mode)
{
    int count = 0, i;
    for (i = 1; i <= 16; i++) {
        char text[128];
        struct EngineRecordLookupKey key;
        sprintf(text, lbl_8037B430, name, i);
        key.value = fn_801F948C(&key, text);
        if (fn_8024A1AC(self, &key, mode))
            count++;
    }
    return count;
}

int fn_8024A120(struct EngineRecordLookupOwner* self, const char* name, int mode)
{
    int count = 0, i;
    for (i = 1; i <= 16; i++) {
        char text[128];
        struct EngineRecordLookupKey key;
        sprintf(text, lbl_8037B430, name, i);
        key.value = fn_801F948C(&key, text);
        if (fn_8024A430(self, &key, mode))
            count++;
    }
    return count;
}
