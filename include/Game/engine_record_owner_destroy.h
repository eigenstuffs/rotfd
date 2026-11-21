#ifndef GAME_ENGINE_RECORD_OWNER_DESTROY_H
#define GAME_ENGINE_RECORD_OWNER_DESTROY_H

#include "Game/engine_group_membership.h"

struct OwnerDestroyRecord {
    Handle_801F7F10 handle;
    char unknown04[0xD0];
};
struct OwnerDestroyArray {
    int count, capacity;
    OwnerDestroyRecord *data;
};
struct OwnerDestroyWrapped { Handle_801F7F10 handle; };
struct OwnerDestroyObject {
    unsigned long key;
    Handle_801F7F10 handle;
    void *table;
    char unknown0C[12];
    signed char active;
    inline signed char isActive() const { return active; }
    char unknown19[7];
    OwnerDestroyArray records;
    int group;
    OwnerDestroyWrapped tail;
};

typedef char CheckOwnerDestroyRecordSize[sizeof(OwnerDestroyRecord) == 0xD4 ? 1 : -1];
extern "C" OwnerDestroyObject *fn_80210FD4(OwnerDestroyObject *, short);

#endif
