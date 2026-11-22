extern "C" {
    void slot18__14CJellyfishMoveFv(void*);
    extern const float lbl_80378C88;
}

struct View {
    char unknown00[0x3D8];
    float field3D8;
};

extern "C" void slot18__15CGreenJfishMoveFv(View* self) {
    slot18__14CJellyfishMoveFv(self);
    self->field3D8 = lbl_80378C88;
}
