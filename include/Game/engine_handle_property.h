#ifndef GAME_ENGINE_HANDLE_PROPERTY_H
#define GAME_ENGINE_HANDLE_PROPERTY_H

struct EnginePropertyHandle { signed int generation : 8; signed int index : 24; };
struct EnginePropertyObject { char unknown00[0x18]; float property; };
struct EnginePropertyEntry {
    struct EnginePropertyObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EnginePropertyManager { char unknown00[8]; struct EnginePropertyEntry* entries; };
struct EnginePropertyOwner { char unknown00[0xB0]; int count, capacity; struct EnginePropertyHandle* items; };
extern struct { char unknown00[0x118]; struct EnginePropertyManager* manager; } lbl_801E9D24;

static inline struct EnginePropertyObject* enginePropertyResolve(const struct EnginePropertyHandle* handle)
{
    struct EnginePropertyEntry* entry = &lbl_801E9D24.manager->entries[handle->index];
    return entry->generation == handle->generation ? entry->object : 0;
}

#endif
