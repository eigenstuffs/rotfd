#ifndef ROTFD_HIERARCHY_ENTRY_RESET_INTERNAL_H
#define ROTFD_HIERARCHY_ENTRY_RESET_INTERNAL_H

// Hierarchy handle array specializations reconstructed from GSQE78.
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}
inline void* operator new(unsigned long, void* p) { return p; }
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
template<int Depth> struct EntryResetHandle : EntryResetHandle<Depth - 1> {
    EntryResetHandle() { value = 0; }
    ~EntryResetHandle() {}
};
template<> struct EntryResetHandle<1> : Handle_801F7F10 {
    EntryResetHandle() { value = 0; }
    ~EntryResetHandle() {}
};
template<class T> struct EntryResetArray {
    int count, capacity;
    T* data;
    void storage(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * sizeof(T), size * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
    void resize(int size, char keepCapacity) {
        int i;
        if (size > count) {
            if (size > capacity || !keepCapacity) {
                storage(size);
                capacity = size;
            }
            for (i = count; i < size; ++i)
                new (data + i) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                data[i].~T();
            if (keepCapacity)
                count = size;
            else {
                storage(size);
                capacity = size;
                count = size;
            }
        }
    }
};

struct Hierarchy {
    char unknown[0xD0];
    EntryResetArray<EntryResetHandle<4> > entries;
};
#endif
