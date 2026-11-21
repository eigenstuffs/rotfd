/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void fn_800A4DAC(void*, unsigned int);
    extern char lbl_802BBC0C[];
}

struct View {
    void* field00;
};

extern "C" View* fn_800A09F0(View* self, unsigned int value1) {
    fn_800A4DAC(self, value1);
    self->field00 = lbl_802BBC0C;
    return self;
}
