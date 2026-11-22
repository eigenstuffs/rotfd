extern "C" {
    void fn_8005BFC4(void*);
    extern char lbl_802B5160[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x88];
    unsigned int field94;
};

extern "C" View* fn_8005CD24(View* self) {
    fn_8005BFC4(self);
    self->field08 = lbl_802B5160;
    self->field94 = 1;
    return self;
}
