#include "Game/engine_nested_arrays_readback.h"
#include "Game/engine_nested_word_arrays_resize.h"

typedef unsigned long NestedReadbackWord;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, NestedReadbackWord, NestedReadbackWord);
void* fn_8028FF24(void*, NestedReadbackWord);
void fn_8028FD50(void*, void*, NestedReadbackWord);
void fn_801D3F04(void*, void*);
void* fn_801E9F40(void*, void*, NestedReadbackWord);
}
inline void* operator new(NestedReadbackWord, void* address)
{
    return address;
}
template<class T> struct NestedReadbackArray {
    int count;
    int capacity;
    T* items;

    inline void storage(int size)
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

    inline void resize(int size)
    {
        int i;
        if (size > count) {
            storage(size);
            capacity = size;
            for (i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};



struct NestedReadbackRecord {
    NestedReadbackArray<NestedReadbackWord> first;
    NestedReadbackArray<NestedReadbackWord> second;
};

struct NestedReadbackOwner {
    char unknown00[0x98];
    int count98;
    int capacity9C;
    NestedReadbackRecord* itemsA0;
};

extern "C" void fn_8026F12C(NestedReadbackOwner* self, void** stream)
{
    fn_801D3F04(self, stream);
    int count;
    *stream = fn_801E9F40(&count, *stream, 4);
    fn_8026F4B4((NestedResizeArray<NestedResizeRecord>*)&self->count98, count, 0);
    for (int i = 0; i < self->count98; ++i) {
        *stream = fn_801E9F40(&count, *stream, 4);
        NestedReadbackArray<NestedReadbackWord>& first = self->itemsA0[i].first;
        first.resize(count);
        *stream = fn_801E9F40(self->itemsA0[i].first.items, *stream, count * 4);
        *stream = fn_801E9F40(&count, *stream, 4);
        self->itemsA0[i].second.resize(count);
        *stream = fn_801E9F40(self->itemsA0[i].second.items, *stream, count * 4);
    }
}
