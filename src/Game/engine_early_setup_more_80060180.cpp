extern "C" {
    void fn_8005BFC4(void*);
    extern char lbl_802B5990[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x88];
    unsigned int field94;
};

extern "C" View* fn_80060180(View* self) {
    fn_8005BFC4(self);
    self->field08 = lbl_802B5990;
    self->field94 = 4;
    return self;
}
