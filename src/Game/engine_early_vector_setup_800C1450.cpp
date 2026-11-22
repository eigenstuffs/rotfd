extern "C" {
    void __ct__15Object_8007F4ACFv(void*);
    extern char lbl_802BF458[];
    extern const float lbl_803794E8;
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x30C];
    void* field318;
    char unknown31C[0xF4];
    float field410;
    unsigned char field414;
    unsigned char field415;
};

extern "C" View* fn_800C1450(View* self) {
    __ct__15Object_8007F4ACFv(self);
    self->field08 = lbl_802BF458;
    self->field318 = lbl_802BF458 + 0x170;
    self->field410 = lbl_803794E8;
    self->field414 = 0;
    self->field415 = 0;
    return self;
}
