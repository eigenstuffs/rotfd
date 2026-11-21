#ifndef GAME_EARLY_CONTROLLER_RESTART_VIEWS_H
#define GAME_EARLY_CONTROLLER_RESTART_VIEWS_H

struct RestartObject;
struct RestartHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};
struct RestartEntry {
    RestartObject* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct RestartManager { int count, capacity; RestartEntry* entries; };
struct RestartContext { char unknown00[0x118]; RestartManager* manager; };
extern "C" RestartContext lbl_801E9D24;
struct RestartObject {
    char unknown00[0x70];
    RestartHandle controller;
    char unknown74[0x3EC - 0x74];
    unsigned char disabled;
};

inline RestartObject* resolveRestart(const RestartHandle& handle) {
    RestartEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

extern "C" {
void fn_8005C6F0(RestartObject*);
signed char fn_8025E9FC(RestartObject*, int);
signed char fn_8007D604(void*, int);
void fn_8007D6A0(void*, int);
}
#endif
