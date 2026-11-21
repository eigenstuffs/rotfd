#include "Game/engine_resource_record_slot.h"

typedef unsigned long Word;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, Word, Word);
void* fn_8028FF24(void*, Word);
void fn_8028FD50(void*, void*, Word);
int fn_80207B94(void*, signed char, int);
}
inline void* operator new(Word, void* p) { return p; }
struct Handle_801F7F10 {
    Word value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ResourceSlotZero : Handle_801F7F10 {
    ResourceSlotZero() { value = 0; }
    ~ResourceSlotZero() {}
};
struct ResourceSlotHandle : ResourceSlotZero {
    ResourceSlotHandle() { value = 0; }
    ~ResourceSlotHandle() {}
};
struct ResourceSlotName {
    Word value;
    ResourceSlotName() { value = 0; }
};
struct ResourceSlotRecord {
    ResourceSlotName name;
    ResourceSlotHandle handle;
    Word value;
    ResourceSlotRecord() { value = 0; }
};
struct ResourceSlotWord {
    Word value;
    ResourceSlotWord() {}
    ~ResourceSlotWord() {}
};
template<class T> struct ResourceSlotArray {
    int count, capacity;
    T* items;
    void storage(int size) {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                    capacity * sizeof(T), size * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }
    void resize(int size) {
        int i;
        if (size > count) {
            storage(size);
            capacity = size;
            for (i = count; i < size; ++i) new(items + i) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i) items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
    void append() {
        if (count + 1 > capacity) {
            storage(capacity + 8);
            capacity += 8;
        }
        new(items + count++) T;
    }
};
struct ResourceSlotBits : ResourceSlotArray<ResourceSlotWord> {
    int size;
    void resizeBits(int n) {
        size = n;
        if (n && ((n >> 5) + 1) > count) resize((size >> 5) + 1);
    }
    void set(int i) { items[i >> 5].value |= 1UL << (i & 31); }
};
struct ResourceSlotPool : ResourceSlotArray<ResourceSlotRecord> {
    ResourceSlotBits occupied;
    int limit, live;
    int vacant() {
        return limit == 0 ? -1 : fn_80207B94(&occupied, 0, 0);
    }
};
extern "C" int fn_8026276C(ResourceSlotPool* self) {
    int index = self->vacant();
    ++self->live;
    if (index == -1) {
        self->append();
        self->occupied.resizeBits(self->limit + 1);
        self->occupied.set(self->limit);
        return self->limit++;
    }
    new(self->items + index) ResourceSlotRecord;
    self->occupied.set(index);
    return index;
}
