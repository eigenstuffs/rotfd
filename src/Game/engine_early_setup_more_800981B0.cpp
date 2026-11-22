extern "C" {
    void fn_800949E0(void*, unsigned int, unsigned int);
    extern char lbl_802BA650[];
}

struct View {
    void* field00;
    unsigned char field04;
};

extern "C" View* fn_800981B0(View* self, unsigned int value1, unsigned int value2) {
    fn_800949E0(self, value1, value2);
    self->field00 = lbl_802BA650;
    self->field04 = 1;
    return self;
}
