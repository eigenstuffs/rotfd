#include "Game/engine_owner_arrays_resize.h"

typedef unsigned long ResizeWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, ResizeWord, ResizeWord);
void* fn_8028FF24(void*, ResizeWord);
void fn_8028FD50(void*, void*, ResizeWord);
void fn_80226AEC(void*, int);
}

inline void* operator new(ResizeWord, void* address)
{
    return address;
}

struct OwnerResizeItem16 {
    ResizeWord words[4];
    OwnerResizeItem16() {}
    ~OwnerResizeItem16() {}
};

struct OwnerResizeItem4 {
    ResizeWord word;
    OwnerResizeItem4() {}
    ~OwnerResizeItem4() {}
};

template<class T> struct OwnerResizeArray {
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
        if (size > count) {
            storage(size);
            capacity = size;
            for (int i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (int i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};

struct OwnerArraysResizeOwner {
    char unknown00[0x1AC];
    OwnerResizeArray<OwnerResizeItem4> first;
    OwnerResizeArray<OwnerResizeItem4> second;
    OwnerResizeArray<OwnerResizeItem4> third;
    OwnerResizeArray<OwnerResizeItem16> fourth;
    OwnerResizeArray<OwnerResizeItem4> fifth;
};

extern "C" void fn_8022FE68(OwnerArraysResizeOwner* self, int size)
{
    fn_80226AEC(self, size);
    self->fourth.resize(size);
    self->fifth.resize(size);
    self->first.resize(size);
    self->second.resize(size);
    self->third.resize(size);
}
