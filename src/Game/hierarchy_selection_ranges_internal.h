// Private reconstructed range-selection layouts and handle accessors.
#ifndef ROTFD_HIERARCHY_SELECTION_RANGES_INTERNAL_H
#define ROTFD_HIERARCHY_SELECTION_RANGES_INTERNAL_H
typedef unsigned long u32;
struct Handle { union { u32 value; struct { signed int generation:8; signed int index:24; } bits; }; };
struct Handle_801F7F10 { Handle_801F7F10(); ~Handle_801F7F10(); Handle token; };
struct Object { char unknown[0xE0]; int width, offset; int getOffset() const { return offset; } int getWidth() const { return width; } };
struct ResourceEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct RangeManagerView { u32 unused[2]; ResourceEntry* entries; };
struct HandleList { int count, capacity; Handle* data; };
struct Groups { char unknown[0x14]; HandleList entries; };
struct ConsoleArguments {
    char unknown[0x860]; int argc;
    char unknown864[0x8A5-0x864]; signed char arg1IsNumeric;
    char unknown8A6[0x8B8-0x8A6]; float arg1Value;
};
struct Globals {
    char unknown[0x110]; ConsoleArguments* console; void* game; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
    Manager* getManager() const { return manager; }
};
extern "C" Globals lbl_801E9D24;
static inline Object* resolve(const Handle& h) {
    ResourceEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
static inline Object* resolveRange(const Handle& h) {
    ResourceEntry* e = ((RangeManagerView*)lbl_801E9D24.manager)->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
extern "C" u32 fn_801F7EB8(const void*);
extern "C" void fn_801F86C8(Manager*, const void*, short);
extern "C" void fn_801FEDA0(Groups*, int);
extern "C" int fn_801FF834(Groups*, int);
extern "C" void fn_802008C8(Object*, int);
struct SelectionRangeHandle : Handle_801F7F10 {
    int getIndex() const { return token.bits.index; }
    signed char getGeneration() const { return token.bits.generation; }
    Object* get() const {
        int index = getIndex();
        ResourceEntry* e = lbl_801E9D24.getManager()->entries + index;
        return e->generation == getGeneration() ? e->object : 0;
    }
    Object* getRange() const {
        ResourceEntry* e = ((RangeManagerView*)lbl_801E9D24.getManager())->entries + token.bits.index;
        return e->generation == getGeneration() ? e->object : 0;
    }
    SelectionRangeHandle(const Handle& source) { token.value = source.value; fn_801F86C8(lbl_801E9D24.getManager(), &source, 1); }
};
#endif
