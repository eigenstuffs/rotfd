#ifndef ROTFD_GROUP_CONSTRUCTOR_INTERNAL_H
#define ROTFD_GROUP_CONSTRUCTOR_INTERNAL_H
// Private reconstructed layouts for the fixed group array constructor.
typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    Handle token;
};
struct Object { char unknown[0x20]; int identifier, order; };
struct Entry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; Entry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
u32 fn_801F948C(void*, const char*);
extern const char lbl_802AD8D8[], lbl_802AD8E8[];
}
struct NameHash {
    u32 value;
    NameHash(const char* name) { value = fn_801F948C(this, name); }
};
extern "C" Handle_801F7F10 fn_801B550C(Manager*, const NameHash&, const NameHash&);
struct GroupHandleLayer1 : Handle_801F7F10 {
    GroupHandleLayer1() { token.value = 0; }
    ~GroupHandleLayer1() {}
};
struct GroupHandleLayer2 : GroupHandleLayer1 {
    GroupHandleLayer2() { token.value = 0; }
    ~GroupHandleLayer2() {}
};
struct GroupTypedHandle : GroupHandleLayer2 {
    GroupTypedHandle(const Handle_801F7F10& source) {
        token = source.token;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct Handle_801FFE58 : GroupHandleLayer2 {
    Handle_801FFE58();
    ~Handle_801FFE58();
    Handle_801FFE58& operator=(const GroupTypedHandle& source) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        token = source.token;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
        return *this;
    }
    Object* get() const {
        int index = token.bits.index;
        char* table = (char*)lbl_801E9D24.manager->entries;
        signed char generation = *(signed char*)(table + index * 16 + 12);
        Entry* entry = (Entry*)(table + index * 16);
        return generation == token.bits.generation ? entry->object : 0;
    }
};
struct HandleList {
    int count, capacity;
    Handle* data;
    HandleList() : count(0), capacity(0), data(0) {}
};
struct Group_801FFC94 {
    Handle_801FFE58 fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
    Group_801FFC94();
};
#endif
