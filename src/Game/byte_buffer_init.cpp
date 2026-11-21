extern "C" {
extern char lbl_8028F698[], lbl_802ED2F0[];
void fn_80249B50(void*);
void* fn_8028FACC(void*, unsigned long);
}

struct InitBuffer {
    void* data;
    unsigned long capacity, count;
    void allocate(unsigned long n) {
        capacity = n;
        data = fn_8028FACC(lbl_8028F698, capacity);
    }
};
struct InitView {
    char unknown00[8];
    void* table;
    char unknown0C[0x30];
    InitBuffer buffer;
};

extern "C" InitView* fn_8026ED8C(InitView* self) {
    fn_80249B50(self);
    self->table = lbl_802ED2F0;
    self->buffer.data = 0;
    self->buffer.capacity = 0;
    self->buffer.count = 0;
    self->buffer.allocate(160);
    return self;
}
