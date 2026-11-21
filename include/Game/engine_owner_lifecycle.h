#ifndef GAME_ENGINE_OWNER_LIFECYCLE_H
#define GAME_ENGINE_OWNER_LIFECYCLE_H
#include "Game/array_interface_tables.h"
#include "Game/platform_native_interface_tables.h"

/* Private layouts observed in the original owner lifecycle routines. */
typedef struct OwnerLifecycleBase { void *table; } OwnerLifecycleBase;
typedef struct OwnerLifecycleHandle { unsigned int word; } OwnerLifecycleHandle;
typedef struct OwnerLifecycleWrapped { OwnerLifecycleHandle handle; } OwnerLifecycleWrapped;
typedef struct OwnerLifecycleRecord {
    OwnerLifecycleWrapped first, second, third;
    char unknown0C[16];
} OwnerLifecycleRecord;
typedef struct OwnerLifecycleFixed {
    char unknown00[0x7C];
    void *table;
    OwnerLifecycleRecord items[32];
} OwnerLifecycleFixed;
typedef struct OwnerLifecycleObject {
    unsigned int unknown00, unknown04;
    void *table;
} OwnerLifecycleObject;

extern unsigned char lbl_802EB000[];
extern unsigned char __vt__13Manipulator_Z[], lbl_801EF5C8[];
extern void fn_801EF610(void *allocator, void *object);
extern void fn_8020C5CC(void *object, int deleting);
extern void fn_801F56A8(void *object, int deleting);
extern void __dt__15Handle_801F7F10Fv(void *handle, int deleting);
extern void __dt__11Activable_ZFv(void *object, int deleting);
extern void __destroy_arr(void *array, void (*destroy)(void *, int), int stride, int count);

OwnerLifecycleBase *fn_8020B774(OwnerLifecycleBase *self, int deleting);
OwnerLifecycleFixed *fn_8020B7DC(OwnerLifecycleFixed *self, int deleting);
OwnerLifecycleRecord *fn_8020B860(OwnerLifecycleRecord *self, int deleting);
OwnerLifecycleObject *fn_8020CA08(OwnerLifecycleObject *self, int deleting);
#endif
