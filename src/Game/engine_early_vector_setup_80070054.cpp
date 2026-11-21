/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void __ct__14Agent_8002B5F4Fv(void*);
    extern char lbl_802B753C[];
    extern char lbl_802B780C[];
    extern const float lbl_803788A8;
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x84];
    unsigned char field90;
    char unknown91[0x3];
    float field94;
    float field98;
};

extern "C" View* fn_80070054(View* self) {
    __ct__14Agent_8002B5F4Fv(self);
    self->field08 = lbl_802B780C;
    self->field90 = 0;
    self->field94 = lbl_803788A8;
    self->field98 = lbl_803788A8;
    self->field08 = lbl_802B753C;
    return self;
}
