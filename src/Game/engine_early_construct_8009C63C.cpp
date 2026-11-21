/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802BB288[];
    extern char lbl_802BB2CC[];
}

struct View {
    void* field00;
    unsigned char field04;
    char unknown05[0x3];
    unsigned int field08;
};

extern "C" View* fn_8009C63C(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802BB2CC;
    self->field08 = value1;
    self->field00 = lbl_802BB288;
    self->field04 = 1;
    return self;
}
