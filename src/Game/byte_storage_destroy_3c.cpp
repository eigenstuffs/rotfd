extern "C" {
extern char lbl_8028F698[], lbl_802ED2F0[], lbl_801EF5C8[];
void fn_8028F8F0(void*, void*, unsigned long);
void fn_802499CC(void*, int);
void fn_801EF610(void*, void*);
}

struct DestroyBuffer {
    void* data;
    unsigned long capacity, count;
    void clear() {
        if (data) fn_8028F8F0(lbl_8028F698, data, capacity);
        data = 0;
        capacity = 0;
        count = 0;
    }
    void reset() { if (capacity) clear(); }
};
struct DestroyView {
    char unknown00[8];
    void* table;
    char unknown0C[0x30];
    DestroyBuffer buffer;
};

extern "C" DestroyView* fn_8026ECC0(DestroyView* self, int deleting) {
    if (self) {
        self->table = lbl_802ED2F0;
        self->buffer.clear();
        if (&self->buffer) self->buffer.clear();
        fn_802499CC(self, 0);
        if ((short)deleting > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
