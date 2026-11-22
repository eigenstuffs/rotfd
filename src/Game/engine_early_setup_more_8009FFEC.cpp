extern "C" {
    void fn_800A4DAC(void*, unsigned int);
    extern char lbl_802BBCB4[];
}

struct View {
    void* field00;
};

extern "C" View* fn_8009FFEC(View* self, unsigned int value1) {
    fn_800A4DAC(self, value1);
    self->field00 = lbl_802BBCB4;
    return self;
}
