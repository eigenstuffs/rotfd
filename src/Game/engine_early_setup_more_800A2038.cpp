extern "C" {
    void fn_800A4DAC(void*, unsigned int);
    extern char lbl_802BB88C[];
}

struct View {
    void* field00;
};

extern "C" View* fn_800A2038(View* self, unsigned int value1) {
    fn_800A4DAC(self, value1);
    self->field00 = lbl_802BB88C;
    return self;
}
