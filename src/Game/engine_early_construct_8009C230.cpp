extern "C" {
    void fn_80090084(void*);
    extern char lbl_802BB2B4[];
    extern char lbl_802BB2CC[];
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
};

extern "C" View* fn_8009C230(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802BB2CC;
    self->field08 = value1;
    self->field00 = lbl_802BB2B4;
    self->field04 = 1;
    return self;
}
