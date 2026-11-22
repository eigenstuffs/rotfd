extern "C" {
    void fn_80224A10(void*);
    extern const float lbl_80378D64;
}

struct View {
    char unknown00[0x22D];
    unsigned char field22D;
    char unknown22E[0x122];
    float field350;
};

extern "C" void slot18__10CActorMoveFv(View* self) {
    fn_80224A10(self);
    self->field22D = 1;
    self->field350 = lbl_80378D64;
}
