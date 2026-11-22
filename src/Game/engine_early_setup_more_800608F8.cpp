extern "C" {
    void fn_8005BFC4(void*);
    extern char lbl_802B5C28[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x88];
    unsigned int field94;
};

extern "C" View* fn_800608F8(View* self) {
    fn_8005BFC4(self);
    self->field08 = lbl_802B5C28;
    self->field94 = 2;
    return self;
}
