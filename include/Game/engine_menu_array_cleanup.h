#ifndef GAME_ENGINE_MENU_ARRAY_CLEANUP_H
#define GAME_ENGINE_MENU_ARRAY_CLEANUP_H

struct EngineMenuCleanupHandle { unsigned int value; };
struct EngineMenuCleanupWrapped { struct EngineMenuCleanupHandle handle; };
struct EngineMenuCleanupNestedItem {
    char unknown00[0x90];
    struct EngineMenuCleanupWrapped first;
    int unknown94;
    struct EngineMenuCleanupWrapped second;
};
struct EngineMenuCleanupFlatItem { char unknown00[144]; };
struct EngineMenuCleanupNestedArray { int count, capacity; struct EngineMenuCleanupNestedItem* items; };
struct EngineMenuCleanupFlatArray { int count, capacity; struct EngineMenuCleanupFlatItem* items; };
struct EngineMenuCleanupNestedOwner {
    char unknown00[8];
    void* vptr;
    char unknown0C[0x40];
    struct EngineMenuCleanupNestedArray array;
    struct EngineMenuCleanupWrapped first, second;
};
struct EngineMenuCleanupFlatOwner {
    char unknown00[8];
    void* vptr;
    char unknown0C[0x40];
    struct EngineMenuCleanupWrapped first, second;
    char unknown54[0x24];
    struct EngineMenuCleanupFlatArray array;
};
extern char lbl_8028F698[], lbl_801EF5C8[], __vt__17MenuPair_802EB2F0[], __vt__18MenuArray_802EB348[];
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
void __dt__15Handle_801F7F10Fv(struct EngineMenuCleanupHandle*, short);
void __dt__17MenuBase_8021D7E4Fv(void*, short);

#endif
