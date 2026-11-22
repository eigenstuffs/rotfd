extern "C" {
    void __ct__9LodMove_ZFv(void*);
    extern char lbl_802EB940[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_8002722C(View* self) {
    __ct__9LodMove_ZFv(self);
    self->field08 = lbl_802EB940;
    return self;
}
