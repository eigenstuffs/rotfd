#include "Game/engine_owner_unique_lists.h"

typedef unsigned long UniqueListsWord;

struct Handle_801F7F10 {
    union {
        UniqueListsWord value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct UniqueListsEntry {
    UniqueListsOwner* owner;
    UniqueListsWord unknown04[2];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};

struct UniqueListsManager {
    UniqueListsWord unknown00[2];
    UniqueListsEntry* entries;
};

struct UniqueListsGlobals {
    char unknown00[0x118];
    UniqueListsManager* manager;
};

extern "C" {
extern UniqueListsGlobals lbl_801E9D24;
extern char lbl_8028F698[], lbl_801EF5C8[];
extern const char lbl_802AE9B8[], lbl_802AE9C8[];
void fn_801F86C8(UniqueListsManager*, const Handle_801F7F10*, short);
void* fn_8028FAF4(void*, void*, UniqueListsWord, UniqueListsWord);
void* fn_8028FF24(void*, UniqueListsWord);
void fn_8028FD50(void*, void*, UniqueListsWord);
void* fn_801EF83C(void*, void*, UniqueListsWord, const char*, const char*, int);
void* fn_801EFA1C(void*, UniqueListsWord, const char*, const char*, int, int);
void fn_801EF610(void*, void*);
}

inline void* operator new(UniqueListsWord, void* address) { return address; }

static inline UniqueListsOwner* resolve(const Handle_801F7F10& handle)
{
    int index = handle.bits.index;
    UniqueListsManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    return generation == handle.bits.generation ? manager->entries[index].owner : 0;
}

struct UniqueListsZeroHandle : Handle_801F7F10 {
    UniqueListsZeroHandle() { value = 0; }
};

struct UniqueListsCopiedHandle : UniqueListsZeroHandle {
    UniqueListsCopiedHandle(const Handle_801F7F10& handle)
    {
        value = 0;
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

struct UniqueListsHandles {
    int count, capacity;
    UniqueListsCopiedHandle* items;

    void storage(int size)
    {
        if (size) {
            if (items)
                items = (UniqueListsCopiedHandle*)fn_8028FAF4(lbl_8028F698,
                    items, capacity * 4, size * 4);
            else
                items = (UniqueListsCopiedHandle*)fn_8028FF24(lbl_8028F698, size * 4);
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * 4);
            items = 0;
        }
    }

    void append(const Handle_801F7F10& handle)
    {
        if (count + 1 > capacity) {
            storage(capacity + 32);
            capacity += 32;
        }
        new (&items[count++]) UniqueListsCopiedHandle(handle);
    }
};

struct UniqueListsArray {
    UniqueListsWord count, capacity;
    UniqueListsWord* items;

    void storage(UniqueListsWord size)
    {
        if (size) {
            if (items)
                items = (UniqueListsWord*)fn_801EF83C(lbl_801EF5C8, items,
                    size * 4, lbl_802AE9B8, lbl_802AE9C8, 0xC4);
            else
                items = (UniqueListsWord*)fn_801EFA1C(lbl_801EF5C8, size * 4,
                    lbl_802AE9B8, lbl_802AE9C8, 0xC6, 4);
        } else if (items) {
            fn_801EF610(lbl_801EF5C8, items);
            items = 0;
        }
    }

    void allocate(UniqueListsWord size)
    {
        storage(size);
        capacity = size;
    }

    void resize(UniqueListsWord size)
    {
        if (size > count) {
            allocate(size);
            capacity = size;
            count = size;
        } else if (size < count) {
            allocate(size);
            count = size;
        }
    }

    void reserve(UniqueListsWord size)
    {
        if (size < count)
            resize(size);
        else
            allocate(size);
    }
};

struct UniqueListsOwner {
    char unknown00[0x60];
    UniqueListsHandles handles;
    char unknown6C[0xC];
    UniqueListsArray first, second, third;
};

extern "C" void fn_8022BE34(UniqueListsOwner* self, const Handle_801F7F10* handle)
{
    int i;
    for (i = 0; i < self->handles.count; ++i) {
        UniqueListsOwner* current = resolve(self->handles.items[i]);
        if (current == resolve(*handle))
            break;
    }
    if (i == self->handles.count) {
        self->handles.append(*handle);
        UniqueListsWord size = i + 1;
        self->first.reserve(size);
        self->second.reserve(size);
        self->third.reserve(size);
    }
}
