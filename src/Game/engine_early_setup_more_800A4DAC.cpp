extern "C" {
    void fn_800A374C(void*, unsigned int);
    extern char lbl_802BC8C8[];
}

struct View {
    void* field00;
    unsigned char field04;
};

extern "C" View* fn_800A4DAC(View* self, unsigned int value1) {
    fn_800A374C(self, value1);
    self->field00 = lbl_802BC8C8;
    self->field04 = 1;
    return self;
}
