#include "Game/engine_render_arrays_readback.h"

typedef unsigned long RenderReadbackWordType;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, RenderReadbackWordType, RenderReadbackWordType);
void* fn_8028FF24(void*, RenderReadbackWordType);
void fn_8028FD50(void*, void*, RenderReadbackWordType);
void fn_801DA8C0(void*, void*);
void* fn_801E9F40(void*, void*, RenderReadbackWordType);
}
inline void* operator new(RenderReadbackWordType, void* address)
{
    return address;
}
struct RenderReadbackWord {
    RenderReadbackWordType value;
    RenderReadbackWord() {}
    ~RenderReadbackWord() {}
};
struct RenderReadbackPair {
    unsigned short first;
    unsigned short second;
    RenderReadbackPair() { first = 0xFFFF; second = 0xFFFF; }
    ~RenderReadbackPair() {}
};
template<class T> struct RenderReadbackArray {
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


struct RenderReadbackOwner {
    char unknown00[0x30];
    RenderReadbackArray<RenderReadbackPair> pairs;
    RenderReadbackArray<RenderReadbackWord> items;
};
extern "C" void fn_8026FE94(RenderReadbackOwner* self, void** stream)
{
    fn_801DA8C0(self, stream);
    int count;
    *stream = fn_801E9F40(&count, *stream, 4);
    self->items.resize(count);
    *stream = fn_801E9F40(self->items.items, *stream, count * 4);
    *stream = fn_801E9F40(&count, *stream, 4);
    self->pairs.resize(count);
}
