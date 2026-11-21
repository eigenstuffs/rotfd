/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void fn_80098AF4(void*);
    extern const float lbl_80378C88;
}

struct View {
    char unknown00[0x3D8];
    float field3D8;
};

extern "C" void fn_80096AD4(View* self) {
    fn_80098AF4(self);
    self->field3D8 = lbl_80378C88;
}
