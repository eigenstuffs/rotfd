/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void __ct__15Object_8002AD98Fv(void*);
    extern char lbl_802B10DC[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_80028184(View* self) {
    __ct__15Object_8002AD98Fv(self);
    self->field08 = lbl_802B10DC;
    return self;
}
