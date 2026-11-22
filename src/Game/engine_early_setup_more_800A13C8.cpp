extern "C" {
    void fn_800A4DAC(void*, unsigned int);
    extern char lbl_802BBABC[];
}

struct View {
    void* field00;
};

extern "C" View* fn_800A13C8(View* self, unsigned int value1) {
    fn_800A4DAC(self, value1);
    self->field00 = lbl_802BBABC;
    return self;
}
