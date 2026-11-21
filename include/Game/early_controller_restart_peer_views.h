#ifndef GAME_EARLY_CONTROLLER_RESTART_PEER_VIEWS_H
#define GAME_EARLY_CONTROLLER_RESTART_PEER_VIEWS_H

struct RestartPeerObject;
struct RestartPeerHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};
struct RestartPeerEntry {
    RestartPeerObject* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct RestartPeerManager { int count, capacity; RestartPeerEntry* entries; };
struct RestartPeerContext { char unknown00[0x118]; RestartPeerManager* manager; };
extern "C" RestartPeerContext lbl_801E9D24;
struct RestartPeerObject {
    char unknown00[0x70];
    RestartPeerHandle controller;
    char unknown74[0x3EC - 0x74];
    unsigned char disabled;
};

inline RestartPeerObject* resolveRestartPeer(const RestartPeerHandle& handle) {
    RestartPeerEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

extern "C" {
void fn_8005C6F0(RestartPeerObject*);
signed char fn_8025E9FC(RestartPeerObject*, int);
signed char fn_8007D604(void*, int);
void fn_8007D6A0(void*, int);
}
#endif
