extern "C" {
    void fn_800A374C(void*, unsigned int);
    extern char lbl_802BC908[];
}

struct View {
    void* field00;
};

extern "C" View* fn_800A4E70(View* self, unsigned int value1) {
    fn_800A374C(self, value1);
    self->field00 = lbl_802BC908;
    return self;
}
