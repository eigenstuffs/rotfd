extern "C" {
    void fn_800A4DAC(void*, unsigned int);
    extern char lbl_802BBC7C[];
}

struct View {
    void* field00;
};

extern "C" View* fn_800A063C(View* self, unsigned int value1) {
    fn_800A4DAC(self, value1);
    self->field00 = lbl_802BBC7C;
    return self;
}
