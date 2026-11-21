#ifndef GAME_INGAME_MANIPULATOR_UPDATE_NATIVE_INTERNAL_H
#define GAME_INGAME_MANIPULATOR_UPDATE_NATIVE_INTERNAL_H
#include "ingame_manipulator_native_internal.h"
struct Node;
struct Transform;
struct RelatedEntry { Transform* object; u32 unknown[2]; signed char generation; char pad[3]; };
struct RelatedManagerView { u32 unknown[2]; RelatedEntry* entries; };
inline Node* resolve(const Handle_801F7F10& h) {
    Entry* entry = lbl_801E9D24.manager->entries + h.bits.index;
    if (entry->generation == h.bits.generation) return (Node*)entry->object;
    return 0;
}
inline Transform* resolveRelated(const Handle_801F7F10& h) {
    RelatedEntry* entry = ((const RelatedManagerView*)lbl_801E9D24.manager)->entries + h.bits.index;
    if (entry->generation == h.bits.generation) return entry->object;
    return 0;
}
struct Transform { char unknown00[0xC8]; float w, x, y, z; };
struct Node { char unknown00[0x44]; Handle_801F7F10 related; };
#endif
