/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void fn_800949E0(void*, unsigned int, unsigned int);
    extern char lbl_802B9760[];
}

struct View {
    void* field00;
    unsigned char field04;
};

extern "C" View* fn_8009587C(View* self, unsigned int value1, unsigned int value2) {
    fn_800949E0(self, value1, value2);
    self->field00 = lbl_802B9760;
    self->field04 = 1;
    return self;
}
