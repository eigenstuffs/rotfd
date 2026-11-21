/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void fn_8005BFC4(void*);
    extern char lbl_802B5690[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x88];
    unsigned int field94;
};

extern "C" View* fn_8005DA68(View* self) {
    fn_8005BFC4(self);
    self->field08 = lbl_802B5690;
    self->field94 = 0;
    return self;
}
