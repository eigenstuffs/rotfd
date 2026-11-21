extern "C" {
extern char lbl_8028F698[];
void fn_801D05D8(void*);
void fn_8028F8F0(void*, void*, unsigned long);
void* fn_8028FACC(void*, unsigned long);
}

struct ResetBuffer {
    void* data;
    unsigned long capacity, count;
    void reset() {
        if (capacity) {
            if (data) fn_8028F8F0(lbl_8028F698, data, capacity);
            data = 0;
            capacity = 0;
            count = 0;
        }
        capacity = 160;
        data = fn_8028FACC(lbl_8028F698, capacity);
    }
};
struct ResetView { char unknown00[0xC0]; ResetBuffer buffer; };

extern "C" void fn_8026EDF4(ResetView* self) {
    fn_801D05D8(self);
    self->buffer.reset();
}
