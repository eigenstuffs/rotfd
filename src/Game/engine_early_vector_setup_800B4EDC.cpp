extern "C" {
    void __ct__15Object_800B4F28Fv(void*);
    extern char lbl_802BD800[];
    extern const float lbl_80379300;
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x198];
    float field1A4;
    unsigned char field1A8;
};

extern "C" View* fn_800B4EDC(View* self) {
    __ct__15Object_800B4F28Fv(self);
    self->field08 = lbl_802BD800;
    self->field1A4 = lbl_80379300;
    self->field1A8 = 0;
    return self;
}
