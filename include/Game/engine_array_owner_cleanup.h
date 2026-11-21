#ifndef GAME_ENGINE_ARRAY_OWNER_CLEANUP_H
#define GAME_ENGINE_ARRAY_OWNER_CLEANUP_H
#include "Game/array_interface_tables.h"
#include "Game/typed_cleanup_tables.h"

struct EngineOwnerItem2 { char unknown00[2]; };
struct EngineOwnerArray2 { int count, capacity; struct EngineOwnerItem2* items; };
struct EngineOwnerItem8 { char unknown00[8]; };
struct EngineOwnerArray8 { int count, capacity; struct EngineOwnerItem8* items; };
struct EngineOwnerItem16 { char unknown00[16]; };
struct EngineOwnerArray16 { int count, capacity; struct EngineOwnerItem16* items; };
struct EngineOwnerItem24 { char unknown00[24]; };
struct EngineOwnerArray24 { int count, capacity; struct EngineOwnerItem24* items; };
struct EngineOwnerItem140 { char unknown00[140]; };
struct EngineOwnerArray140 { int count, capacity; struct EngineOwnerItem140* items; };
struct EngineArrayOwnerPair {
    void* vptr;
    char unknown04[0x18];
    struct EngineOwnerArray24 first;
    struct EngineOwnerArray140 second;
};
struct EngineArrayOwnerTriple {
    struct EngineOwnerArray8 first;
    struct EngineOwnerArray16 second;
    struct EngineOwnerArray2 third;
};
struct EngineOwnerHandle { unsigned int value; };
struct EngineOwnerHandleItem { struct EngineOwnerHandle handle; };
struct EngineOwnerHandleArray { int count, capacity; struct EngineOwnerHandleItem* items; };
struct EngineArrayOwnerHandles { struct EngineOwnerHandleArray array; int unknown0C; void* vptr10; };

extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
void __dt__15Handle_801F7F10Fv(struct EngineOwnerHandle*, short);

#endif
