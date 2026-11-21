// Validated access to a handle registry entry's flag byte.
typedef unsigned long u32;
struct Handle { signed int generation : 8; signed int index : 24; };
struct Entry { void* object; u32 unknown[2]; signed char generation, flags; char padding[2]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" signed char fn_801F8C88(Manager* self, const Handle& handle) {
    signed char generation = handle.generation;
    int index = handle.index;
    int valid = false;
    if (index < self->count && generation == *((signed char*)self->entries + index * sizeof(Entry) + 12))
        valid = true;
    if (valid)
        return *((signed char*)self->entries + index * sizeof(Entry) + 13);
    return 0;
}
extern "C" void fn_801F8CF0(Manager* self, const Handle& handle, signed char value) {
    signed char generation = handle.generation;
    int index = handle.index;
    int valid = false;
    if (index < self->count && generation == *((signed char*)self->entries + index * sizeof(Entry) + 12))
        valid = true;
    if (valid)
        *((signed char*)self->entries + index * sizeof(Entry) + 13) = value;
}
