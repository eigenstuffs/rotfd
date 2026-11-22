extern "C" {
    void fn_80237924(void*);
}

struct View {
    char unknown00[0xC4];
    unsigned char fieldC4;
    char unknownC5[0x3];
    unsigned int fieldC8;
};

extern "C" void fn_800761F0(View* self) {
    fn_80237924(self);
    self->fieldC4 = 1;
    self->fieldC8 = 70;
}
