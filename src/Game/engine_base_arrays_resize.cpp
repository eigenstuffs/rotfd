#include "Game/engine_base_arrays_resize.h"

typedef unsigned long BaseResizeWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, BaseResizeWord, BaseResizeWord);
void* fn_8028FF24(void*, BaseResizeWord);
void fn_8028FD50(void*, void*, BaseResizeWord);
void fn_802271C0(void*, int);
}

inline void* operator new(BaseResizeWord, void* address)
{
    return address;
}

struct BaseResizeItem12 {
    BaseResizeWord words[3];
    BaseResizeItem12() {}
    ~BaseResizeItem12() {}
};

struct BaseResizeItem16 {
    BaseResizeWord words[4];
    BaseResizeItem16() {}
    ~BaseResizeItem16() {}
};

struct BaseResizeItem40 {
    char unknown00[0x10];
    BaseResizeWord count;
    BaseResizeWord pointer;
    char unknown18[0x10];
    BaseResizeItem40() { pointer = 0; count = 0; }
    ~BaseResizeItem40() {}
};

struct Handle_801F7F10 {
    BaseResizeWord word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct BaseResizeZeroHandle : Handle_801F7F10 {
    BaseResizeZeroHandle() { word = 0; }
    ~BaseResizeZeroHandle() {}
};

struct BaseResizeHandle : BaseResizeZeroHandle {
    BaseResizeHandle() { word = 0; }
    ~BaseResizeHandle() {}
};

template<class T> struct BaseResizeArray {
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

struct BaseArraysResizeOwner {
    char unknown00[0x38];
    BaseResizeArray<BaseResizeItem12> first;
    BaseResizeArray<BaseResizeItem16> second;
    BaseResizeArray<BaseResizeItem12> third;
    BaseResizeArray<BaseResizeHandle> fourth;
    BaseResizeWord unknown68;
    BaseResizeArray<BaseResizeItem40> fifth;
    char unknown78[0x108];
    char subarray180[0xC];
};

extern "C" void fn_80226AEC(BaseArraysResizeOwner* self, int size)
{
    fn_802271C0(self->subarray180, size);
    self->first.resize(size);
    self->second.resize(size);
    self->third.resize(size);
    self->fourth.resize(size);
    self->fifth.resize(size);
}
