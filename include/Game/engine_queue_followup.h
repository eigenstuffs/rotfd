#ifndef GAME_ENGINE_QUEUE_FOLLOWUP_H
#define GAME_ENGINE_QUEUE_FOLLOWUP_H

// Observed prefixes. Original virtual methods and tables retain their owners.
struct EngineFollowupHandle { signed int tag : 8; signed int index : 24; };
struct EngineFollowupStorage { unsigned int unknown00, identity; };
struct EngineFollowupTarget : EngineFollowupStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48(int, float, float, float, float, float, int);
    virtual void slot4C(int, float, float);
};
struct EngineFollowupEntry {
    EngineFollowupTarget *object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct EngineFollowupManager { char unknown00[8]; EngineFollowupEntry *entries; };
struct EngineFollowupOwner { char unknown00[0x1F8]; EngineFollowupHandle handle; };
struct EngineFollowupQueue {
    char unknown00[0xC];
    EngineFollowupHandle owner, target, handles[8];
    int values[8], count, cursor;
    signed char finished, dirty;
};
struct EngineFollowupRecord {
    char unknown00[4];
    short index;
    char unknown06[0x4A];
};
struct EngineFollowupRecordList {
    char unknown00[0xC];
    int count, capacity;
    EngineFollowupRecord *data;
};
struct EngineFollowupHandleList {
    char unknown00[0x20];
    int count, capacity;
    EngineFollowupHandle *data;
};
struct EngineFollowupWork { char unknown00[0x2C]; };
typedef char EngineFollowupHandleSize[(sizeof(EngineFollowupHandle) == 4) ? 1 : -1];
typedef char EngineFollowupEntrySize[(sizeof(EngineFollowupEntry) == 0x10) ? 1 : -1];
typedef char EngineFollowupQueueSize[(sizeof(EngineFollowupQueue) == 0x60) ? 1 : -1];
typedef char EngineFollowupRecordSize[(sizeof(EngineFollowupRecord) == 0x50) ? 1 : -1];

extern "C" {
extern struct { char unknown00[0x118]; EngineFollowupManager *manager; } lbl_801E9D24;
EngineFollowupTarget *fn_801F7EB8(const EngineFollowupHandle *);
void fn_802139D8(EngineFollowupTarget *);
void fn_80213A18(EngineFollowupTarget *);
void fn_802073E8(void *, int, EngineFollowupTarget *, float);
extern const float lbl_8037B1D0;
void fn_801C6968(void *);
void __construct_array(void *, void (*)(void *), void (*)(void *), unsigned int, unsigned int);
void fn_801AED04(EngineFollowupRecord *, EngineFollowupTarget *, EngineFollowupWork *, int *, float, float, float);
}

static inline EngineFollowupTarget *engineFollowupResolve(const EngineFollowupHandle &handle) {
    EngineFollowupEntry *entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->tag == handle.tag ? entry->object : 0;
}

#endif
