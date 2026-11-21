/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802BC04C[];
}

struct View {
    void* field00;
    char unknown04[0x4];
    unsigned int field08;
};

extern "C" View* fn_800A374C(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802BC04C;
    self->field08 = 0;
    self->field08 = value1;
    return self;
}
