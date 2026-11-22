extern "C" {
    void fn_800949E0(void*, unsigned int, unsigned int);
    extern char lbl_802B9730[];
}

struct View {
    void* field00;
    unsigned char field04;
};

extern "C" View* fn_80095BB4(View* self, unsigned int value1, unsigned int value2) {
    fn_800949E0(self, value1, value2);
    self->field00 = lbl_802B9730;
    self->field04 = 1;
    return self;
}
