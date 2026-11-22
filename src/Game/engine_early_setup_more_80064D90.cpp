extern "C" {
    void __ct__21CallbackPair_802EC798Fv(void*);
    extern char lbl_802B66F4[];
    extern char lbl_802B6774[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x64];
    unsigned int field70;
};

extern "C" View* fn_80064D90(View* self) {
    __ct__21CallbackPair_802EC798Fv(self);
    self->field08 = lbl_802B6774;
    self->field08 = lbl_802B66F4;
    self->field70 = 0;
    return self;
}
