/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void __ct__15Object_8002AD98Fv(void*);
    extern char lbl_802BFCFC[];
}

struct View {
    char unknown00[0x8];
    void* field08;
};

extern "C" View* fn_800C5354(View* self) {
    __ct__15Object_8002AD98Fv(self);
    self->field08 = lbl_802BFCFC;
    return self;
}
