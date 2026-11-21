#ifndef ROTFD_INGAME_MANIPULATOR_UPDATE_INTERNAL_H
#define ROTFD_INGAME_MANIPULATOR_UPDATE_INTERNAL_H

// Private observed views: signed generation/index handles and 16-byte records.
typedef unsigned long u32;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct Node; struct Transform;
struct Entry { Node* object; u32 unknown[2]; signed char generation; char pad[3]; };
struct Manager { u32 unknown[2]; Entry* entries; };
struct RelatedEntry { Transform* object; u32 unknown[2]; signed char generation; char pad[3]; };
struct RelatedManagerView { u32 unknown[2]; RelatedEntry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" Globals lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    Entry* entry = lbl_801E9D24.manager->entries + h.bits.index;
    if (entry->generation == h.bits.generation) return entry->object;
    return 0;
}
inline Transform* resolveRelated(const Handle& h) {
    RelatedEntry* entry = ((const RelatedManagerView*)lbl_801E9D24.manager)->entries + h.bits.index;
    if (entry->generation == h.bits.generation) return entry->object;
    return 0;
}
struct Transform { char unknown00[0xC8]; float w,x,y,z; };
struct Node { char unknown00[0x44]; Handle related; };
struct InGameObjectsManipulator_802128A0 { char unknown[0x20]; Handle handle; };

typedef char CheckHandleSize[sizeof(Handle) == 4 ? 1 : -1];
typedef char CheckEntrySize[sizeof(Entry) == 16 ? 1 : -1];
typedef char CheckRelatedEntrySize[sizeof(RelatedEntry) == 16 ? 1 : -1];
typedef char CheckManipulatorSize[sizeof(InGameObjectsManipulator_802128A0) == 0x24 ? 1 : -1];
#endif
