/* fn_8023A6D8: for a valid handle, append a counted copy to the handle array
 * (count, capacity, items; grown by 32) unless an entry already resolves to
 * the same object. Same shapes as owner_handle_unique_append_8022B830.cpp. */
struct OwnerUniqueAppendView;

typedef unsigned long OwnerUniqueAppendWord;
/* Signed packed indices retain their value semantics at the registry boundary. */
struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};

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
    bool matchesGeneration(signed char tag) const { return generation == tag; }
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
unsigned long fn_801F7EB8(const Handle_801F7F10*);
void* fn_8028FAF4(void*, void*, OwnerUniqueAppendWord, OwnerUniqueAppendWord);
void* fn_8028FF24(void*, OwnerUniqueAppendWord);
void fn_8028FD50(void*, void*, OwnerUniqueAppendWord);
}

inline void* operator new(OwnerUniqueAppendWord, void* address) { return address; }

static inline OwnerUniqueAppendView* resolve(const Handle_801F7F10& handle)
{
    OwnerUniqueAppendManager* manager = lbl_801E9D24.manager;
    const HandleIndex index(handle.bits.index);
    signed char generation = handle.bits.generation;
    if (manager->entries[index].matchesGeneration(generation))
        return manager->entries[index].owner;
    return 0;
}

struct OwnerUniqueAppendCopiedHandle : Handle_801F7F10 {
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
            storage(capacity + 32);
            capacity += 32;
        }
        new (&items[count++]) OwnerUniqueAppendCopiedHandle(handle);
    }
};

struct OwnerUniqueAppendView {
    OwnerUniqueAppendHandles handles;
};

extern "C" void fn_8023A6D8(OwnerUniqueAppendView* self, const Handle_801F7F10* handle)
{
    if (fn_801F7EB8(handle)) {
        char found = 0;
        int i;
        for (i = 0; !found && i < self->handles.count; ++i) {
            const Handle_801F7F10& item = self->handles.items[i];
            if (resolve(*handle) == resolve(item))
                found = 1;
        }
        if (!found)
            self->handles.append(*handle);
    }
}
