#include "Game/handle_array_stream_read_801cb414.h"

typedef unsigned long MultiHandleReadWordType;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, MultiHandleReadWordType, MultiHandleReadWordType);
void* fn_8028FF24(void*, MultiHandleReadWordType);
void fn_8028FD50(void*, void*, MultiHandleReadWordType);
void fn_80243E44(void*, void*);
void fn_801B41B8(void*, void*, void*);
void fn_801B41F4(void*, void*, void*);
void* fn_801E9F40(void*, void*, MultiHandleReadWordType);
}

inline void* operator new(MultiHandleReadWordType, void* address)
{
    return address;
}

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct MultiHandleReadZero : Handle_801F7F10 {
    MultiHandleReadZero() { value = 0; }
    ~MultiHandleReadZero() {}
};

struct MultiHandleReadValue : MultiHandleReadZero {
    MultiHandleReadValue() { value = 0; }
    ~MultiHandleReadValue() {}
};

struct MultiHandleReadBlob {
    char data[128];
    MultiHandleReadBlob() {}
    ~MultiHandleReadBlob() {}
};

template <class T> struct MultiHandleReadArray {
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

struct MultiHandleReadGlobals {
    char unknown00[0x118];
    void* manager;
};

extern "C" MultiHandleReadGlobals lbl_801E9D24;

struct MultiHandleReadOwner {
    char unknown00[0x74];
    MultiHandleReadArray<MultiHandleReadBlob> blobs;
    char raw80[8];
    MultiHandleReadZero handles[10];
    char rawB0[40];
    MultiHandleReadArray<MultiHandleReadZero> first;
    MultiHandleReadArray<MultiHandleReadValue> second;
    unsigned long finalF0;
    unsigned long finalF4;
};

extern "C" void fn_801CB414(MultiHandleReadOwner* self, void** stream)
{
    fn_80243E44(self, stream);
    int count;
    int i;
    *stream = fn_801E9F40(&count, *stream, 4);
    self->blobs.resize(count);
    *stream = fn_801E9F40(self->blobs.items, *stream,
        self->blobs.count * sizeof(MultiHandleReadBlob));
    *stream = fn_801E9F40(self->raw80, *stream, sizeof(self->raw80));
    for (i = 0; i < 10; ++i)
        fn_801B41B8(lbl_801E9D24.manager, &self->handles[i], stream);
    *stream = fn_801E9F40(self->rawB0, *stream, sizeof(self->rawB0));
    *stream = fn_801E9F40(&count, *stream, 4);
    self->first.resize(count);
    for (i = 0; i < count; ++i)
        fn_801B41B8(lbl_801E9D24.manager, &self->first.items[i], stream);
    *stream = fn_801E9F40(&count, *stream, 4);
    self->second.resize(count);
    for (i = 0; i < count; ++i)
        fn_801B41B8(lbl_801E9D24.manager, &self->second.items[i], stream);
    fn_801B41F4(lbl_801E9D24.manager, &self->finalF0, stream);
    *stream = fn_801E9F40(&self->finalF4, *stream, sizeof(self->finalF4));
}
