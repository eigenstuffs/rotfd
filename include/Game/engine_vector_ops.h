#ifndef GAME_ENGINE_VECTOR_OPS_H
#define GAME_ENGINE_VECTOR_OPS_H

struct EngineVectorHandle {
    signed int tag : 8;
    signed int index : 24;
};
struct EngineVectorStorage {
    unsigned int unknown00, identity;
};
struct EngineVectorTarget : EngineVectorStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct EngineVectorEntry {
    EngineVectorTarget* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct EngineVectorManager {
    char unknown00[8];
    EngineVectorEntry* entries;
};
struct EngineVectorOwner {
    unsigned int unknown00, identity;
    void* vptr;
    char unknown0C[0x20];
    float m00, m01, unknown34, m10, m11, unknown40, x, y;
    char unknown4C[4];
    float angle, centerX, centerY, scaleX, scaleY;
    char unknown64[0xC];
    unsigned char flags;
    char unknown71[3];
    EngineVectorHandle handles[2];
};
struct EngineVectorCurveOwner {
    char unknown00[0xB8];
    EngineVectorHandle handle;
};

extern "C" {
extern struct {
    char unknown00[0x118];
    EngineVectorManager* manager;
} lbl_801E9D24;
signed char slot1C__12BaseObject_ZFv(void*);
EngineVectorTarget* fn_801F7EB8(const EngineVectorHandle*);
void fn_801B0E28(void*);
float fn_8028506C(float);
float fn_80284FA8(float);
extern const float lbl_8037B2F8;
extern char __vt__22BasisResource_802EBFD8[], __vt__17Resource_802E9E20[], lbl_801EF5C8[];
void __destroy_arr(void*, void (*)(void*, int), unsigned int, unsigned int);
void __dt__15Handle_8003F47CFv(void*, int);
void __dt__12BaseObject_ZFv(void*, int);
void fn_801EF610(void*, void*);
}

static inline EngineVectorTarget* engineVectorResolve(const EngineVectorHandle& handle)
{
    EngineVectorEntry* entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->tag == handle.tag ? entry->object : 0;
}

typedef char EngineVectorHandleSize[sizeof(EngineVectorHandle) == 4 ? 1 : -1];
typedef char EngineVectorOwnerSize[sizeof(EngineVectorOwner) == 0x7C ? 1 : -1];

#endif
