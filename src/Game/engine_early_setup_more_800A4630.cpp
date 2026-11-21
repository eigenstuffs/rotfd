/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void fn_800A4CF0(void*, unsigned int);
    extern char lbl_802BC4A4[];
}

struct View {
    void* field00;
    unsigned char field04;
};

extern "C" View* fn_800A4630(View* self, unsigned int value1) {
    fn_800A4CF0(self, value1);
    self->field00 = lbl_802BC4A4;
    self->field04 = 1;
    return self;
}
