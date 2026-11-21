#ifndef GAME_ENGINE_GROUP_RECORD_UPDATE_H
#define GAME_ENGINE_GROUP_RECORD_UPDATE_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct GroupUpdateObject {
    char unknown00[0x1C];
    Handle_801F7F10 first, second;
    char unknown24[12];
    Handle_801F7F10 child;
};
struct GroupUpdateEntry {
    GroupUpdateObject *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
};
struct GroupUpdateManager { int count, capacity; GroupUpdateEntry *entries; };
struct GroupUpdateContext {
    char unknown00[0x118];
    GroupUpdateManager *manager;
    char unknown11C[0x150 - 0x11C];
    void *recordManager;
};
extern "C" {
extern GroupUpdateContext lbl_801E9D24;
void fn_801F86C8(GroupUpdateManager *, const Handle_801F7F10 *, short);
unsigned long fn_801F7EB8(const Handle_801F7F10 *);
void fn_8021D51C(void *, void *);
unsigned long fn_801E5FDC(void *, void *, int, Handle_801F7F10 *);
signed char fn_801E5D78(void *, unsigned long, Handle_801F7F10 *);
void fn_8023D648(GroupUpdateObject *);
void fn_8023DE28(GroupUpdateObject *);
}
struct GroupUpdateZero : Handle_801F7F10 {
    GroupUpdateZero() { value = 0; }
};
struct GroupUpdateHandle : GroupUpdateZero {
    GroupUpdateHandle() { value = 0; }
};
struct GroupUpdateRecord {
    char unknown00[0x80];
    unsigned long value80, value84, value88;
    unsigned short value8C;
    Handle_801F7F10 handle90;
    unsigned long value94;
    Handle_801F7F10 handle98;
};
struct GroupUpdateArray { int count, capacity; GroupUpdateRecord *data; };
struct GroupUpdateOwner {
    char unknown00[0x20];
    Handle_801F7F10 first;
    char unknown24[4];
    short selected;
    char unknown2A[0x4C - 0x2A];
    GroupUpdateArray records;
    Handle_801F7F10 second;
};

typedef char CheckGroupUpdateRecordSize[sizeof(GroupUpdateRecord) == 0x9C ? 1 : -1];
extern "C" void fn_8021B230(GroupUpdateOwner *, void *);

#endif
