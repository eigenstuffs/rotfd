#ifndef GAME_ENGINE_RECORD_CLEAR_H
#define GAME_ENGINE_RECORD_CLEAR_H

struct EngineRecordClearHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct EngineRecordClearNode {
    char unknown00[0xC];
    unsigned int flags0C;
    char unknown10[0x110];
    unsigned int flags120;
};
struct EngineRecordClearEntry {
    struct EngineRecordClearNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineRecordClearManager {
    char unknown00[8];
    struct EngineRecordClearEntry* entries;
};
struct EngineRecordClearRow {
    int count, capacity;
    int* items;
};
struct EngineRecordClearOwner {
    char unknown00[0x20];
    int targetCount, targetCapacity;
    struct EngineRecordClearHandle* targets;
    char unknown2C[0x38];
    int count, capacity;
    struct EngineRecordClearHandle* items;
    int rowCount, rowCapacity;
    struct EngineRecordClearRow* rows;
};

extern struct {
    char unknown00[0x118];
    struct EngineRecordClearManager* manager;
} lbl_801E9D24;
extern const char lbl_8037B438[6];
int fn_8024A120(struct EngineRecordClearOwner*, const char*, int);
void fn_8024C5D4(struct EngineRecordClearOwner*);

static inline struct EngineRecordClearNode* engineRecordClearResolve(const struct EngineRecordClearHandle* handle)
{
    struct EngineRecordClearEntry* entry = &lbl_801E9D24.manager->entries[handle->index];
    return entry->generation == handle->generation ? entry->object : 0;
}

#endif
