// Private ABI views for the Activable handle list and its borrowed update cursor.
#ifndef GAME_OWNER_LIST_INTERNAL_H
#define GAME_OWNER_LIST_INTERNAL_H

typedef unsigned long u32;
struct ListObject;
struct ListEntry {
    ListObject* object;
    u32 unknown[2];
    signed char generation;
    char padding[3];
    signed char getGeneration() const { return generation; }
};
struct ListManager { int count, capacity; ListEntry* entries; };
struct ListGlobals { char unknown[0x118]; ListManager* manager; };
extern "C" {
extern ListGlobals lbl_801E9D24;
void fn_801F86C8(ListManager*, const void*, short);
}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ListHandle : Handle_801F7F10 {
    ListHandle() { value = 0; }
    ListHandle& operator=(const ListHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    ListObject* get() const {
        int index = bits.index;
        ListManager* manager = lbl_801E9D24.manager;
        int generation = manager->entries[index].getGeneration();
        if (generation == bits.generation)
            return manager->entries[index].object;
        return 0;
    }
};
struct ListObjectPrefix { u32 unknown0, identity; };
struct ListObject : ListObjectPrefix {
    virtual ~ListObject();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void update(float);
    ListHandle prev, next;
    int mode;
    signed char active;
};
struct OwnerList_80213824 {
    ListHandle head, tail;
    signed char mode8Only;
    char padding9[3];
    OwnerList_80213824();
};
typedef char OwnerListSizeCheck[sizeof(OwnerList_80213824) == 0xC ? 1 : -1];
typedef char ListObjectPrefixSizeCheck[sizeof(ListObject) == 0x1C ? 1 : -1];
typedef char ListEntrySizeCheck[sizeof(ListEntry) == 16 ? 1 : -1];

#endif
