#ifndef GAME_ENGINE_VECTOR_OWNER_H
#define GAME_ENGINE_VECTOR_OWNER_H

typedef struct EngineVectorStorage {
    char unknown00[12];
    int width;
    void* items;
} EngineVectorStorage;

typedef struct EngineVectorOwnerHandle { unsigned int word; } EngineVectorOwnerHandle;
typedef struct EngineVectorOwnerWrapped { EngineVectorOwnerHandle handle; } EngineVectorOwnerWrapped;
typedef struct EngineVectorOwner {
    char unknown00[8];
    void* table;
    char unknown0C[20];
    EngineVectorOwnerWrapped first;
    char unknown24[4];
    EngineVectorOwnerWrapped second;
} EngineVectorOwner;

extern char lbl_801EF5C8[], lbl_802AE024[], lbl_802AE3C8[];
extern char lbl_802EB040[], lbl_802EB090[], __vt__13Manipulator_Z[];
extern void fn_801EAC8C(EngineVectorStorage* self, int rows, int width);
extern void fn_801EF610(void* allocator, void* object);
extern void* fn_801EFA1C(void* allocator, unsigned int bytes, const char* category,
                       const char* source, int line, int alignment);
extern void* __construct_new_array(void* allocation, void (*construct)(void*),
                                   void (*destroy)(void*, int),
                                   unsigned int stride, unsigned int count);
extern void __ct__16Vector3_801D5330Fv(void* vector);
extern void fn_8020C0C4(void* vector);
extern void __dt__15Handle_801F7F10Fv(void* handle, int deleting);
extern void __dt__11Activable_ZFv(void* object, int deleting);

void fn_8020BECC(EngineVectorStorage* self, int rows, int width);
void fn_8020C018(EngineVectorStorage* self, int rows, int width);
EngineVectorOwner* fn_8020CEA8(EngineVectorOwner* self, int deleting);

#endif
