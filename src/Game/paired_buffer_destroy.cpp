extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

struct PairedBufferView {
    char unknown00[0x1C38];
    void* first;
    void* second;
};

extern "C" PairedBufferView* fn_8027BAD4(PairedBufferView* self, int deleting)
{
    if (self) {
        if (self->first)
            fn_801EF610(lbl_801EF5C8, self->first);
        if (self->second)
            fn_801EF610(lbl_801EF5C8, self->second);
        self->first = 0;
        self->second = 0;
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
