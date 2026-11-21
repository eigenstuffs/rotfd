/* Destructor of the lbl_802ED240 class (fn_8026E2D8, vtable slot 2; the
 * constructor is fn_8026E7C4 in twelve_word_init.cpp). Shrinks the two plain
 * arrays at 0xEC (16-byte items) and 0xF8 (words) to zero, clears every byte
 * buffer of the 0x104 buffer array, shrinks it to zero, clears the buffer at
 * 0x110, runs the member destructors in reverse order and chains to the base
 * destructor fn_801CEED0. The symbol is a plain extern "C" name (the vtable
 * in platform_native_method_tables_802ED178.cpp references fn_8026E2D8), so
 * no rename is needed.
 *
 * Matching note: the resize destroy loop must index through the array's
 * operator[] ((*this)[i].~T()), and the clear loop through buffers[i]; plain
 * items[i] swaps the element-pointer and offset registers. */
typedef unsigned long Word;
extern "C" {
extern char lbl_8028F698[], lbl_801EF5C8[], lbl_802ED240[];
void fn_8028F8F0(void*, void*, Word);
void fn_8028FD50(void*, void*, Word);
void* fn_8028FAF4(void*, void*, Word, Word);
void* fn_8028FF24(void*, Word);
void fn_801EF610(void*, void*);
void* fn_801CEED0(void*, int);
}
inline void* operator new(Word, void* p) { return p; }

struct Item16 { Word words[4]; Item16() {} ~Item16() {} };
struct Item4 { Word word; Item4() {} ~Item4() {} };
struct Buffer {
    void* data;
    Word capacity, count;
    Buffer() { data = 0; capacity = 0; count = 0; }
    void clear() {
        if (data) fn_8028F8F0(lbl_8028F698, data, capacity);
        data = 0;
        capacity = 0;
        count = 0;
    }
    ~Buffer() { clear(); }
};

template<class T> struct Array {
    int count, capacity;
    T* items;
    T& operator[](int i) { return items[i]; }
    void storage(int size) {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items, capacity * sizeof(T), size * sizeof(T));
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
            if (size > capacity) {
                storage(size);
                capacity = size;
            }
            for (i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                (*this)[i].~T();
            count = size;
        }
    }
    ~Array() {
        if (items) {
            for (int i = 0; i < count; ++i)
                items[i].~T();
            if (items) {
                fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
                items = 0;
            }
            items = 0;
        }
    }
};

struct Owner {
    char unknown00[8];
    void* table;
    char unknown0C[0xE0];
    Array<Item16> first;
    Array<Item4> second;
    Array<Buffer> buffers;
    Buffer buffer;
};

extern "C" Owner* fn_8026E2D8(Owner* self, short deleting) {
    if (self) {
        self->table = lbl_802ED240;
        self->first.resize(0);
        self->second.resize(0);
        short i;
        short n = self->buffers.count;
        for (i = 0; i < n; ++i)
            self->buffers[i].clear();
        self->buffers.resize(0);
        self->buffer.clear();
        self->buffer.~Buffer();
        self->buffers.~Array<Buffer>();
        self->second.~Array<Item4>();
        self->first.~Array<Item16>();
        fn_801CEED0(self, 0);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
