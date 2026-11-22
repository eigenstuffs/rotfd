extern "C" {
    void fn_80081378(void*, unsigned int, unsigned int);
    extern char lbl_802C8DF8[];
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3B];
    unsigned char field40;
    unsigned char field41;
    unsigned char field42;
    unsigned char field43;
    char unknown44[0x4];
    unsigned int field48;
    unsigned int field4C;
};

extern "C" View* fn_800E582C(View* self, unsigned int value1, unsigned int value2) {
    fn_80081378(self, value1, value2);
    self->field00 = lbl_802C8DF8;
    self->field40 = 1;
    self->field41 = 0;
    self->field42 = 1;
    self->field43 = 0;
    self->field48 = 0;
    self->field4C = 0;
    self->field04 = 0;
    return self;
}
