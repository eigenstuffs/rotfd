#include "Game/engine_screen_arrays_readback.h"

typedef unsigned long ScreenReadbackWordType;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, ScreenReadbackWordType, ScreenReadbackWordType);
void* fn_8028FF24(void*, ScreenReadbackWordType);
void fn_8028FD50(void*, void*, ScreenReadbackWordType);
void fn_801DAB34(void*, void*);
void* fn_801E9F40(void*, void*, ScreenReadbackWordType);
}
inline void* operator new(ScreenReadbackWordType, void* address)
{
    return address;
}
struct ScreenReadbackWord {
    ScreenReadbackWordType value;
    ScreenReadbackWord() {}
    ~ScreenReadbackWord() {}
};
struct ScreenReadbackPair {
    unsigned short first;
    unsigned short second;
    ScreenReadbackPair() { first = 0xFFFF; second = 0xFFFF; }
    ~ScreenReadbackPair() {}
};
template<class T> struct ScreenReadbackArray {
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


struct ScreenReadbackOwner {
    char unknown00[0xA4];
    int countA4;
    char unknownA8[0xFC - 0xA8];
    ScreenReadbackArray<ScreenReadbackPair> pairs;
    ScreenReadbackArray<ScreenReadbackWord> items;
};
extern "C" void fn_8027024C(ScreenReadbackOwner* self, void** stream)
{
    fn_801DAB34(self, stream);
    int count;
    *stream = fn_801E9F40(&count, *stream, 4);
    self->items.resize(count);
    *stream = fn_801E9F40(self->items.items, *stream, count * 4);
    self->pairs.resize(self->countA4);
}
