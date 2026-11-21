#include "Game/engine_owner_unique_append.h"

typedef unsigned long OwnerUniqueAppendWord;

struct Handle_801F7F10 {
    union {
        OwnerUniqueAppendWord value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct OwnerUniqueAppendEntry {
    OwnerUniqueAppendView* owner;
    OwnerUniqueAppendWord unknown04[2];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};

struct OwnerUniqueAppendManager {
    OwnerUniqueAppendWord unknown00[2];
    OwnerUniqueAppendEntry* entries;
};

struct OwnerUniqueAppendGlobals {
    char unknown00[0x118];
    OwnerUniqueAppendManager* manager;
};

extern "C" {
extern OwnerUniqueAppendGlobals lbl_801E9D24;
extern char lbl_8028F698[];
void fn_801F86C8(OwnerUniqueAppendManager*, const Handle_801F7F10*, short);
void* fn_8028FAF4(void*, void*, OwnerUniqueAppendWord, OwnerUniqueAppendWord);
void* fn_8028FF24(void*, OwnerUniqueAppendWord);
void fn_8028FD50(void*, void*, OwnerUniqueAppendWord);
}

inline void* operator new(OwnerUniqueAppendWord, void* address) { return address; }

static inline OwnerUniqueAppendView* resolve(const Handle_801F7F10& handle)
{
    int index = handle.bits.index;
    OwnerUniqueAppendManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    return generation == handle.bits.generation ? manager->entries[index].owner : 0;
}

struct OwnerUniqueAppendZeroHandle : Handle_801F7F10 {
    OwnerUniqueAppendZeroHandle() { value = 0; }
};

struct OwnerUniqueAppendCopiedHandle : OwnerUniqueAppendZeroHandle {
    OwnerUniqueAppendCopiedHandle(const Handle_801F7F10& handle)
    {
        value = 0;
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

struct OwnerUniqueAppendHandles {
    int count, capacity;
    OwnerUniqueAppendCopiedHandle* items;

    void storage(int size)
    {
        if (size) {
            if (items)
                items = (OwnerUniqueAppendCopiedHandle*)fn_8028FAF4(lbl_8028F698,
                    items, capacity * 4, size * 4);
            else
                items = (OwnerUniqueAppendCopiedHandle*)fn_8028FF24(lbl_8028F698, size * 4);
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * 4);
            items = 0;
        }
    }

    void append(const Handle_801F7F10& handle)
    {
        if (count + 1 > capacity) {
            storage(capacity + 8);
            capacity += 8;
        }
        new (&items[count++]) OwnerUniqueAppendCopiedHandle(handle);
    }
};

struct OwnerUniqueAppendView {
 char unknown00[0x6C];
 OwnerUniqueAppendHandles handles;
};

extern "C" void fn_8022BB30(OwnerUniqueAppendView* self, const Handle_801F7F10* handle)
{
    int i;
    for (i = 0; i < self->handles.count; ++i) {
        OwnerUniqueAppendView* current = resolve(self->handles.items[i]);
        if (current == resolve(*handle))
            break;
    }
    if (i == self->handles.count) {
        self->handles.append(*handle);
    }
}
