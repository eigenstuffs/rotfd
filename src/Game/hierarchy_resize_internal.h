#ifndef ROTFD_HIERARCHY_RESIZE_INTERNAL_H
#define ROTFD_HIERARCHY_RESIZE_INTERNAL_H

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
template<int Depth> struct HierarchyResizeHandle : HierarchyResizeHandle<Depth - 1> {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<> struct HierarchyResizeHandle<1> : Handle_801F7F10 {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<class T> struct ResizeArray {
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
};

#endif
