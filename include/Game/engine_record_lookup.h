#ifndef GAME_ENGINE_RECORD_LOOKUP_H
#define GAME_ENGINE_RECORD_LOOKUP_H

struct EngineRecordLookupKey {
    unsigned int value;
};
struct EngineRecordLookupHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct EngineRecordLookupObject {
    struct EngineRecordLookupKey key;
};
struct EngineRecordLookupEntry {
    struct EngineRecordLookupObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineRecordLookupManager {
    char unknown00[8];
    struct EngineRecordLookupEntry* entries;
};
struct EngineRecordLookupOwner {
    char unknown00[0x64];
    int count, capacity;
    struct EngineRecordLookupHandle* items;
};

extern struct {
    char unknown00[0x118];
    struct EngineRecordLookupManager* manager;
} lbl_801E9D24;
extern const char lbl_8037B430[7];
int sprintf(char*, const char*, ...);
unsigned int fn_801F948C(struct EngineRecordLookupKey*, const char*);
signed char fn_8024A1AC(struct EngineRecordLookupOwner*, const struct EngineRecordLookupKey*, int);
signed char fn_8024A430(struct EngineRecordLookupOwner*, const struct EngineRecordLookupKey*, int);
unsigned int fn_801F7EB8(const struct EngineRecordLookupHandle*);

static inline struct EngineRecordLookupObject* engineRecordLookupResolve(const struct EngineRecordLookupHandle* handle)
{
    struct EngineRecordLookupEntry* entry = &lbl_801E9D24.manager->entries[handle->index];
    return entry->generation == handle->generation ? entry->object : 0;
}

#endif
