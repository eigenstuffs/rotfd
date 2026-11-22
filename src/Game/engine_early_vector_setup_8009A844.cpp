extern "C" {
    void __ct__15Object_8009A9D8Fv(void*);
    extern char lbl_802BAE04[];
    extern const float lbl_80378D48;
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x30C];
    void* field318;
    char unknown31C[0x74];
    unsigned int field390;
    float field394;
    float field398;
    float field39C;
    float field3A0;
    float field3A4;
    unsigned int field3A8;
};

extern "C" View* fn_8009A844(View* self) {
    __ct__15Object_8009A9D8Fv(self);
    self->field08 = lbl_802BAE04;
    self->field318 = lbl_802BAE04 + 0x170;
    self->field390 = 0;
    self->field394 = lbl_80378D48;
    self->field398 = lbl_80378D48;
    self->field39C = lbl_80378D48;
    self->field3A0 = lbl_80378D48;
    self->field3A4 = lbl_80378D48;
    self->field3A8 = 0;
    return self;
}
