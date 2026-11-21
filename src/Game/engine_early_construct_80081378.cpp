/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802B92B0[];
}

struct View {
    void* field00;
    char unknown04[0x4];
    unsigned int field08;
    unsigned int field0C;
};

extern "C" View* fn_80081378(View* self, unsigned int value1, unsigned int value2) {
    fn_80090084(self);
    self->field00 = lbl_802B92B0;
    self->field08 = 0;
    self->field0C = 0;
    self->field08 = value1;
    self->field0C = value2;
    return self;
}
