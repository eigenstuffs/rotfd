#ifndef GAME_ENGINE_ARRAY_CLEANUP_H
#define GAME_ENGINE_ARRAY_CLEANUP_H

struct EngineCleanupItem16 { char unknown00[16]; };
struct EngineCleanupArray16 {
    int count, capacity;
    struct EngineCleanupItem16* items;
};
struct EngineCleanupArray28 { int count, capacity; void* items; };
struct EngineCleanupArray2 { int count, capacity; unsigned short* items; };
struct EngineCleanupOwner {
    int unknown00, unknown04;
    void* vptr08;
    char unknown0C[0x18];
    struct EngineCleanupArray2 first;
    struct EngineCleanupArray28 second;
};

extern char lbl_8028F698[], lbl_801EF5C8[], lbl_802EC268[];
void fn_801D4BDC(struct EngineCleanupItem16*, short);
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
void __dt__22SpatialRecord_802EA440Fv(struct EngineCleanupOwner*, short);
struct EngineCleanupArray16* fn_8024D3AC(struct EngineCleanupArray16*, short);
struct EngineCleanupOwner* fn_802499CC(struct EngineCleanupOwner*, short);

#endif
