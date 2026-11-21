#include "Game/engine_nested_word_arrays_resize.h"

typedef unsigned long NestedResizeWord;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, NestedResizeWord, NestedResizeWord);
void* fn_8028FF24(void*, NestedResizeWord);
void fn_8028FD50(void*, void*, NestedResizeWord);
}
inline void* operator new(NestedResizeWord, void* address)
{
    return address;
}
struct NestedResizeItem {
    NestedResizeWord value;
    NestedResizeItem() {}
    ~NestedResizeItem() {}
};
template<class T> struct NestedResizeArray {
    int count;
    int capacity;
    T* items;

    NestedResizeArray() { count = 0; capacity = 0; items = 0; }
    ~NestedResizeArray()
    {
        if (items) {
            for (int i = 0; i < count; ++i)
                items[i].~T();
            storage(0);
            items = 0;
        }
    }

    void storage(int size)
    {
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
};

struct NestedResizeRecord {
    NestedResizeArray<NestedResizeItem> first;
    NestedResizeArray<NestedResizeItem> second;
    NestedResizeRecord() {}
    ~NestedResizeRecord() {}
};

extern "C" void fn_8026F4B4(NestedResizeArray<NestedResizeRecord>* self,
    int size, signed char retain)
{
    int i;
    if (size > self->count) {
        if (size > self->capacity || !retain) {
            self->storage(size);
            self->capacity = size;
        }
        for (i = self->count; i < size; ++i)
            new (&self->items[i]) NestedResizeRecord;
        self->count = size;
    } else if (size < self->count) {
        for (i = self->count - 1; i >= size; --i)
            self->items[i].~NestedResizeRecord();
        if (retain) {
            self->count = size;
        } else {
            self->storage(size);
            self->capacity = size;
            self->count = size;
        }
    }
}
